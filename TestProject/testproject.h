#ifndef TESTPROJECT_H
#define TESTPROJECT_H

#include <QtGui/QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
 
#include <QWebFrame>
#include <QDirIterator>
#include <QThread>
#include <QtCore/QCoreApplication>
#include "ui_testproject.h"

class DBUpdateWorker;

class TestProject : public QMainWindow
{
	Q_OBJECT
public slots:
	void UpdateDBFinished();

public:
	TestProject(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestProject();
	void scanDirIter(QDir dir);


	bool openDB();
	QSqlError lastError();
	bool deleteDB();

	bool PlayFile(int ID);

private slots:
    void on_pushButton_pressed();
    void on_pushButton_2_pressed();

    void on_ButtonStop_pressed();
    void on_ButtonPause_pressed();
    void on_ButtonNext_pressed();
    void on_PlayButton_pressed();
    void on_PreviousButton_pressed();

    void on_videoPlayer_finished();

	void on_webView_loadFinished(bool arg1);

private:
	void GetMaxRnd();
	//Объект
	Phonon::MediaObject* PhononObject;
	//Аудио выход
	Phonon::AudioOutput* PhononOutput;

	Ui::TestProjectClass ui;
    QSqlDatabase db;

	int MaxRndInt;
	int PrevID;
	int CurrentID;

	DBUpdateWorker *worker;
	QThread *workerThread;
};


class DBUpdateWorker : public QObject
 {
     Q_OBJECT
 private:
	QSqlDatabase db;
	QDir dir;
	Ui::TestProjectClass ui;
	TestProject* TP;

 public:
	DBUpdateWorker(QSqlDatabase db, QDir dir, Ui::TestProjectClass ui, TestProject* TP)
	{
		this->db = db;
		this->dir = dir;
		this->ui = ui;
		this->TP = TP;
	}
	~DBUpdateWorker(){};

 signals:
	void wUpdateDBFinished();

 public slots:

	 void doWork() 
	 {
		if (db.isOpen())
		{
			QSqlQuery query;
			query.exec("TRUNCATE TABLE person;");

			QDirIterator iterator(dir.absolutePath(), QDirIterator::Subdirectories);
			short int status = 0;
			while (iterator.hasNext()) 
			{
			  iterator.next();
			  if (!iterator.fileInfo().isDir()) {
				 QString filename = iterator.fileName();
				 if (filename.endsWith(".mp3"))
				 {
					bool ret = false;
					ret = query.exec("insert into person (name) VALUES ('" + iterator.filePath() + "');");
				 }
			  }
			}
		}
		this->thread()->terminate();
     }
 };

#endif // TESTPROJECT_H
