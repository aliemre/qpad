#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    filename = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Choose a file to open");

    if (!file.isEmpty()) {
        QFile sFile(file);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            filename = file;
            QTextStream in(&sFile);
            QString newText = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(newText);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(filename);

    if (sFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&sFile);

        out << ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save the file");

    if (!file.isEmpty()) {
        filename = file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    messageBox.setText("Developed by Ali Emre Cakmakoglu - 2015");
    messageBox.exec();

}
