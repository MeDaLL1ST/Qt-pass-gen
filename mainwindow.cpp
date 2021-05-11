#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui (new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_but_g_clicked(){
    bool ch_zz=ui->ch_z->isChecked();
    bool ch_cc=ui->ch_c->isChecked();
    bool ch_ss=ui->ch_s->isChecked();
    QString slenght=ui->t_len->toPlainText();
    int len=slenght.toInt();

    char chars1[] = "1234567890";
    char chars2[] = "qwertyuiopasdfghjklzxcvbnm";
    char chars3[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char chars4[] = ":;/.,\[)(-+[!?><'}{|=^$#";

    char password[len+1];
    for(int i;i<len;i++){
        int randchar1 = rand() % 10;
        int randchar23 = rand() % 26;
        int randchar4 = rand() % 24;
        if (!ch_zz&&!ch_cc&&!ch_ss){
        password[i]=chars2[randchar23];
        } else if (ch_zz&&ch_cc&&ch_ss){
            int p = rand() % 5;
            if (p==1)
                password[i]=chars1[randchar1];

            if (p==2)
                password[i]=chars2[randchar23];

            if (p==3)
                password[i]=chars3[randchar23];

            if (p==4)
                password[i]=chars4[randchar4];
        } else if(ch_zz&&ch_cc){
            int p = rand() % 4;
            if (p==1)
                password[i]=chars3[randchar23];

            if (p==2)
                password[i]=chars1[randchar1];

            if (p==3)
                password[i]=chars2[randchar23];
        } else if (ch_zz&&ch_ss){
            int p = rand() % 4;
            if (p==1)
                password[i]=chars4[randchar4];

            if (p==2)
                password[i]=chars3[randchar23];

            if (p==3)
                password[i]=chars2[randchar23];
        } else if (ch_ss&&ch_cc){
            int p = rand() % 4;
            if (p==1)
                password[i]=chars4[randchar4];

            if (p==2)
                password[i]=chars1[randchar1];

            if (p==3)
                password[i]=chars2[randchar23];
        } else if (ch_ss) {
            int p = rand() % 3;
            if (p==1)
                password[i]=chars2[randchar23];

            if (p==2)
                password[i]=chars4[randchar4];
        } else if (ch_cc) {
            int p = rand() % 3;
            if (p==1)
                password[i]=chars2[randchar23];

            if (p==2)
                password[i]=chars1[randchar1];
        } else if (ch_zz) {
            int p = rand() % 3;
            if (p==1)
                password[i]=chars2[randchar23];

            if (p==2)
                password[i]=chars3[randchar23];
        } else {
            password[i]=chars2[randchar23];
        }
    }
    ui->t_p->setText(password);
}
void MainWindow::on_but_c_clicked(){
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->t_p->toPlainText());
}
