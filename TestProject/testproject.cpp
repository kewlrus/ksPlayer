#include "testproject.h"

bool TestProject::PlayFile(int ID)
{
	QSqlQuery query;
	QMessageBox msgBox;
	bool res = false;

    if (db.isOpen())
    {
		QString IDstr = QString::number(ID);
		res = query.exec("select * from person where id=" + IDstr);

		if (res)
		{
			while (query.next()) 
			{
				PrevID = CurrentID;
				CurrentID = ID;
				PhononObject->setCurrentSource(Phonon::MediaSource(query.value(1).toString()));
				Phonon::createPath(PhononObject, PhononOutput);
				PhononObject->play();

				ui.textBrowser->append(QString::fromUtf8("playing ") + query.value(1).toString());
				//msgBox.setText(query.value(1).toString());
				//msgBox.exec();
			}//
		}

	}

	return res;
}

void TestProject::on_videoPlayer_finished()
{
	if (ui.TrueRndCheckBox->checkState() != Qt::Checked)
		PlayFile( qrand() % ((MaxRndInt + 1)));
	else
		ui.webView->reload();
}


TestProject::TestProject(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	PrevID = -1;
	CurrentID = -1;

	//connect();

	PhononObject = ui.videoPlayer->mediaObject();
	PhononOutput = ui.videoPlayer->audioOutput();

	ui.seekSlider->setMediaObject(PhononObject);
	ui.volumeSlider->setAudioOutput(PhononOutput);

	bool res = openDB();

	GetMaxRnd();  
}

void TestProject::GetMaxRnd()
{
	if (db.isOpen())
	{
		QSqlQuery query;
		bool res = query.exec("select count(*) from person");

		if (res)
		{
			while (query.next()) 
			{
				MaxRndInt = query.value(0).toInt() - 1;
				if (MaxRndInt >= 0)
				{
					QString MaxRnd = QString::number(MaxRndInt);
					//sequences/?min=1&max=52&col=1&format=plain&rnd=new
					//ui.webView->setUrl(QUrl(QString::fromUtf8("http://www.random.org/sequences/?min=1&max=") + MaxRnd + QString::fromUtf8("&col=") + MaxRnd + QString::fromUtf8("&format=plain&rnd=new")));
					
					ui.webView->setUrl(QUrl(QString::fromUtf8("http://www.random.org/integers/?num=1&min=0&max=") + MaxRnd + QString::fromUtf8("&col=1&base=10&format=plain&rnd=new")));
				}
			}
		}

	}
}

TestProject::~TestProject()
{
	PhononObject->stop();
	//while (PhononObject->state() != Phonon::StoppedState);
	delete PhononObject;
	delete PhononOutput;

    db.close();
}

void TestProject::scanDirIter(QDir dir)
{
	worker = new DBUpdateWorker(db, dir, ui, this);
	workerThread = new QThread(NULL);

	bool res = false;
	res = connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
	res = connect(workerThread, SIGNAL(terminated()), this, SLOT(UpdateDBFinished()));
	worker->moveToThread(workerThread);

	// Starts an event loop, and emits workerThread->started()
	workerThread->start();
}

void TestProject::UpdateDBFinished()
{
	delete worker;
	delete workerThread;

	GetMaxRnd();  
	ui.textBrowser->append(QString::fromUtf8("Updating finished, restart appriciated ;)"));
}

void TestProject::on_webView_loadFinished(bool arg1)
{
	if (arg1)
	{
		if (ui.TrueRndCheckBox->checkState() != Qt::Checked)
		{
			if (MaxRndInt >= 0)
				PlayFile( qrand() % ((MaxRndInt + 1)));
		}
		else
		{
			int rnd = ui.webView->page()->currentFrame()->toPlainText().toInt();

			QString strrnd = QString::number(rnd);
			PlayFile(rnd);
		}
	}
}

void TestProject::on_ButtonStop_pressed()
{
	PhononObject->stop();
}

void TestProject::on_ButtonPause_pressed()
{
	if (PhononObject->state() != Phonon::PausedState)
		PhononObject->pause();
	else
		PhononObject->play();
	
	ui.ButtonPause->setFlat(!ui.ButtonPause->isFlat());
}

void TestProject::on_ButtonNext_pressed()
{
	if (ui.TrueRndCheckBox->checkState() != Qt::Checked)
		PlayFile( qrand() % ((MaxRndInt + 1)));
	else
		ui.webView->reload();
}

void TestProject::on_PlayButton_pressed()
{
	if (PhononObject->state() == Phonon::PausedState)
		PhononObject->play();
	else
	{
		if (ui.TrueRndCheckBox->checkState() != Qt::Checked)
			PlayFile( qrand() % ((MaxRndInt + 1)));
		else
			ui.webView->reload();
	}
}

void TestProject::on_pushButton_2_pressed()
{
	
//	ui.MusicP
	if (ui.MusicPathTextEdit->toPlainText() != "")
	{
		QString DirPath(ui.MusicPathTextEdit->toPlainText());
		QDir Directory(DirPath);

		if (Directory.exists())
		{
			ui.textBrowser->append(QString::fromUtf8("Updating... be pacient, please."));
			scanDirIter(Directory);
		}
		else
			ui.textBrowser->append(QString::fromUtf8("Path doesn't exists!"));
	}
	else
		ui.textBrowser->append(QString::fromUtf8("Enter path to music!"));
}

void TestProject::on_pushButton_pressed()
{
	if (ui.TrueRndCheckBox->checkState() != Qt::Checked)
		PlayFile( qrand() % ((MaxRndInt + 1)));
	else
		ui.webView->reload();
	//ui.webView->reload();
}

void TestProject::on_PreviousButton_pressed()
{
	if (PrevID > 0)
		PlayFile(PrevID);
	//ui.webView->reload();
}

bool TestProject::openDB()
    {
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
 
    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
    #else
    // NOTE: File exists in the application private folder, in Symbian Qt implementation
    db.setDatabaseName("my.db.sqlite");
    #endif
 
    // Open databasee
	db.open();
	
    bool ret = false;
    if (db.isOpen())
    {
		ui.textBrowser->append(QString::fromUtf8("DB opened successfully!"));
		QSqlQuery query;
		ret = query.exec("create table person "
				  "(id integer primary key, "
				  "name text UNIQUE) ");

		/*ret = query.exec("create table sequence "
				  "(id integer primary key, "
				  "played integer, "
				  "number integer) ");*/
    }
	else
		ui.textBrowser->append(QString::fromUtf8("DB open failed!"));
    return ret;
    }
 
QSqlError TestProject::lastError()
    {
    // If opening database has failed user can ask 
    // error description by QSqlError::text()
    return db.lastError();
    }
 
bool TestProject::deleteDB()
    {
    // Close database
    db.close();
 
    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
    #else
 
    // Remove created database binary file
    return QFile::remove("my.db.sqlite");
    #endif
    }