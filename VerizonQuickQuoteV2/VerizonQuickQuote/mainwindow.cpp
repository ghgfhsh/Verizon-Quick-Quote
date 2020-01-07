#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <QIntValidator>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainFuncion(){

    //declartions
    //get value from each phones total price and convert to Int
    int totalpriceEditInput = ui->totalpriceEdit->text().toInt();
    int totalpriceEditInput2 = ui->totalpriceEdit2->text().toInt();
    int totalpriceEditInput3 = ui->totalpriceEdit3->text().toInt();
    int totalpriceEditInput4 = ui->totalpriceEdit4->text().toInt();
    int totalpriceEditInput5 = ui->totalpriceEdit5->text().toInt();

    //declair variables for DPI
    double DPI = ui->DPIinput->text().toDouble();
    double DPI2 = ui->DPIinput2->text().toDouble();
    double DPI3 = ui->DPIinput3->text().toDouble();
    double DPI4 = ui->DPIinput4->text().toDouble();
    double DPI5= ui->DPIinput5->text().toDouble();


    //get tax input and divide by 100
    double taxInputPercent = ui->taxPercentageEdit->text().toDouble();

    taxInputPercent = taxInputPercent / 100.0;
    //declare variables for tax calulation
    double taxInput;
    double taxInput2;
    double taxInput3;
    double taxInput4;
    double taxInput5;


    //get value from each phones downpayment and convert to Int
    int phonedownpaymentEditInput = ui->DownpaymentEdit->text().toInt();
    int phonedownpaymentEditInput2 = ui->DownpaymentEdit2->text().toInt();
    int phonedownpaymentEditInput3 = ui->DownpaymentEdit3->text().toInt();
    int phonedownpaymentEditInput4 = ui->DownpaymentEdit4->text().toInt();
    int phonedownpaymentEditInput5 = ui->DownpaymentEdit5->text().toInt();

    //declare doubles for monthly for each phone
    double phonemonthly;
    double phonemonthly2;
    double phonemonthly3;
    double phonemonthly4;
    double phonemonthly5;

    //Qstrings for monthly's
    QString phonemonthlyQS;
    QString phonemonthlyQS2;
    QString phonemonthlyQS3;
    QString phonemonthlyQS4;
    QString phonemonthlyQS5;

    //Qstrings for taxes
    QString taxInputQS;
    QString taxInputQS2;
    QString taxInputQS3;
    QString taxInputQS4;
    QString taxInputQS5;


    //math

    //subtract downpayment from total
    phonemonthly = totalpriceEditInput - phonedownpaymentEditInput;
    phonemonthly2 = totalpriceEditInput2 - phonedownpaymentEditInput2;
    phonemonthly3 = totalpriceEditInput3 - phonedownpaymentEditInput3;
    phonemonthly4 = totalpriceEditInput4 - phonedownpaymentEditInput4;
    phonemonthly5 = totalpriceEditInput5 - phonedownpaymentEditInput5;


    //subtract DPI from monthly
    phonemonthly = phonemonthly - DPI;
    phonemonthly2 = phonemonthly2 - DPI2;
    phonemonthly3 = phonemonthly3 - DPI3;
    phonemonthly4 = phonemonthly4 - DPI4;
    phonemonthly5 = phonemonthly5 - DPI5;

    //Figure out monthly price
    phonemonthly = phonemonthly / 24.0;
    phonemonthly2 = phonemonthly2 / 24.0;
    phonemonthly3 = phonemonthly3 / 24.0;
    phonemonthly4 = phonemonthly4 / 24.0;
    phonemonthly5 = phonemonthly5 / 24.0;

     //figure out taxes owed
    taxInput = totalpriceEditInput * taxInputPercent;
    taxInput2 = totalpriceEditInput2 * taxInputPercent;
    taxInput3 = totalpriceEditInput3 * taxInputPercent;
    taxInput4 = totalpriceEditInput4 * taxInputPercent;
    taxInput5 = totalpriceEditInput5 * taxInputPercent;

    //Convert Monthly to string
    phonemonthlyQS = QString::number(phonemonthly, 'f', 2);
    phonemonthlyQS2 = QString::number(phonemonthly2, 'f', 2);
    phonemonthlyQS3 = QString::number(phonemonthly3, 'f', 2);
    phonemonthlyQS4 = QString::number(phonemonthly4, 'f', 2);
    phonemonthlyQS5 = QString::number(phonemonthly5, 'f', 2);

    //convert taxes to string
    taxInputQS = QString::number(taxInput, 'f', 2);
    taxInputQS2 = QString::number(taxInput2, 'f', 2);
    taxInputQS3 = QString::number(taxInput3, 'f', 2);
    taxInputQS4 = QString::number(taxInput4, 'f', 2);
    taxInputQS5 = QString::number(taxInput5, 'f', 2);


    //display


    //phone 1 (check to make sure you are using this line
    if(ui->phoneinclude->isChecked()){
        ui->Monthly->setText(phonemonthlyQS); //all of display the monthly owed per phone
        ui->Taxes->setText(taxInputQS); //all of these display taxes owed per phone
    }
    //phone 2
    if(ui->phoneinclude2->isChecked()){
        ui->Monthly2->setText(phonemonthlyQS2);
        ui->Taxes2->setText(taxInputQS2);
    }
    //phone 3
    if(ui->phoneinclude3->isChecked()){
        ui->Monthly3->setText(phonemonthlyQS3);
        ui->Taxes3->setText(taxInputQS3);
    }
    //phone 4
    if(ui->phoneinclude4->isChecked()){
        ui->Monthly4->setText(phonemonthlyQS4);
            ui->Taxes4->setText(taxInputQS4);
    }
    //phone 5
    if(ui->phoneinclude5->isChecked()){
        ui->Monthly5->setText(phonemonthlyQS5);
           ui->Taxes5->setText(taxInputQS5);
    }

    //Totals
    //get double values for monthly and check if they are included
    double totalmonthlyT = ui->Monthly->text().toDouble();
    if(ui->phoneinclude->isChecked() == false)
        totalmonthlyT = 0;
    double totalmonthlyT2 = ui->Monthly2->text().toDouble();
    if(ui->phoneinclude2->isChecked() == false)
        totalmonthlyT2 = 0;
    double totalmonthlyT3 = ui->Monthly3->text().toDouble();
    if(ui->phoneinclude3->isChecked() == false)
        totalmonthlyT3 = 0;
    double totalmonthlyT4 = ui->Monthly4->text().toDouble();
    if(ui->phoneinclude4->isChecked() == false)
        totalmonthlyT4 = 0;
    double totalmonthlyT5 = ui->Monthly5->text().toDouble();
    if(ui->phoneinclude5->isChecked() == false)
        totalmonthlyT5 = 0;

    //Get values for the monthly plan owed if they are included.
    int monthlyplan = ui->monthlyplanInput->text().toInt();
    if(ui->phoneinclude->isChecked() == false)
        monthlyplan = 0;
    int monthlyplan2 = ui->monthlyplanInput2->text().toInt();
    if(ui->phoneinclude2->isChecked() == false)
        monthlyplan2 = 0;
    int monthlyplan3 = ui->monthlyplanInput3->text().toInt();
    if(ui->phoneinclude3->isChecked() == false)
        monthlyplan3 = 0;
    int monthlyplan4 = ui->monthlyplanInput4->text().toInt();
    if(ui->phoneinclude4->isChecked() == false)
        monthlyplan4 = 0;
    int monthlyplan5 = ui->monthlyplanInput5->text().toInt();
    if(ui->phoneinclude5->isChecked() == false)
        monthlyplan5 = 0;


    //add total monthly and display
    double totalmonthly = totalmonthlyT + totalmonthlyT2 + totalmonthlyT3 + totalmonthlyT4 + totalmonthlyT5 + monthlyplan + monthlyplan2 + monthlyplan3 + monthlyplan4 + monthlyplan5;
    QString totalmonthlyQS = QString::number(totalmonthly, 'f', 2);
    ui->totalmonthlyOut->setText(totalmonthlyQS);

    //get total taxes (eventually add total for plan
    double totaldownT = ui->Taxes->text().toDouble();
    if(ui->phoneinclude->isChecked() == false)
        totaldownT = 0;
    double totaldownT2 = ui->Taxes2->text().toDouble();
    if(ui->phoneinclude2->isChecked() == false)
        totaldownT2 = 0;
    double totaldownT3 = ui->Taxes3->text().toDouble();
    if(ui->phoneinclude3->isChecked() == false)
        totaldownT3 = 0;
    double totaldownT4 = ui->Taxes4->text().toDouble();
    if(ui->phoneinclude4->isChecked() == false)
        totaldownT4 = 0;
    double totaldownT5 = ui->Taxes5->text().toDouble();
    if(ui->phoneinclude5->isChecked() == false)
        totaldownT5 = 0;

    //get total downpayments
    double totaldownpay = phonedownpaymentEditInput;
    if(ui->phoneinclude->isChecked() == false)
            totaldownpay = 0;
    double totaldownpay2 = phonedownpaymentEditInput2;
    if(ui->phoneinclude2->isChecked() == false)
            totaldownpay2 = 0;
    double totaldownpay3 = phonedownpaymentEditInput3;
    if(ui->phoneinclude3->isChecked() == false)
            totaldownpay3 = 0;
    double totaldownpay4 = phonedownpaymentEditInput4;
    if(ui->phoneinclude4->isChecked() == false)
            totaldownpay4 = 0;
    double totaldownpay5 = phonedownpaymentEditInput5;
    if(ui->phoneinclude5->isChecked() == false)
            totaldownpay5 = 0;

    //add total down and display
    double totaldown = totaldownT + totaldownT2 + totaldownT3 + totaldownT4 + totaldownT5 + totaldownpay + totaldownpay2 + totaldownpay3 + totaldownpay4 + totaldownpay5;
    QString totaldownQS = QString::number(totaldown, 'f', 5);
    ui->totaldownOut->setText(totaldownQS);

    //declares for scope
    int maxDown = ui->fianancemaxEdit->text().toInt();
    QString totalcheckdisplay;
    int totalcheck;
    int totalcheckP;
    int totalcheckP2;
    int totalcheckP3;
    int totalcheckP4;
    int totalcheckP5;

    //check to see if you are over the max you are allowed to finance

    //check if phone is included and if it is find how much is left over being financed after downpayment
    //phone 1
    if(ui->phoneinclude->isChecked() == true){
        totalcheckP = totalpriceEditInput - phonedownpaymentEditInput;
    }
    if(ui->phoneinclude->isChecked() == false){
        totalcheckP = 0;
    }
    //phone 2
    if(ui->phoneinclude2->isChecked() == true){
        totalcheckP2 = totalpriceEditInput2 - phonedownpaymentEditInput2;
    }
    if(ui->phoneinclude2->isChecked() == false){
        totalcheckP2 = 0;
    }
    //phone 3
    if(ui->phoneinclude3->isChecked() == true){
        totalcheckP3 = totalpriceEditInput3 - phonedownpaymentEditInput3;
    }
    if(ui->phoneinclude3->isChecked() == false){
        totalcheckP3 = 0;
    }
    //phone 4
    if(ui->phoneinclude4->isChecked() == true){
        totalcheckP4 = totalpriceEditInput4 - phonedownpaymentEditInput4;
    }
    if(ui->phoneinclude4->isChecked() == false){
        totalcheckP4 = 0;
    }
    //phone 5
    if(ui->phoneinclude5->isChecked() == true){
        totalcheckP5 = totalpriceEditInput5 - phonedownpaymentEditInput5;
    }
    if(ui->phoneinclude5->isChecked() == false){
        totalcheckP5 = 0;
    }

    //add total downpayments and see if you are still under the max amount financed, run check on it, and display output based on result
    totalcheck = totalcheckP + totalcheckP2 + totalcheckP3 + totalcheckP4 + totalcheckP5;

    double totalchecki = maxDown - totalcheck;

    totalcheckdisplay = QString::number(totalchecki, 'f', 2);


    if(totalcheck > maxDown)
        ui->overmaxCheck->setText("You are over the maximum finance limit by, " + totalcheckdisplay + " please increase downpayments");
    if(totalcheck <= maxDown)
        ui->overmaxCheck->setText("");
    if(maxDown == 0)
        ui->overmaxCheck->setText("");

}


//update when you edit the total price
void MainWindow::on_totalpriceEdit_editingFinished()
{
   mainFuncion();
}

void MainWindow::on_totalpriceEdit2_editingFinished()
{
   mainFuncion();
}

void MainWindow::on_totalpriceEdit3_editingFinished()
{
   mainFuncion();
}

void MainWindow::on_totalpriceEdit4_editingFinished()
{
   mainFuncion();
}

void MainWindow::on_totalpriceEdit5_editingFinished()
{
   mainFuncion();
}

//update when you edit downpayment

void MainWindow::on_DownpaymentEdit_editingFinished()
{
    on_totalpriceEdit_editingFinished();
}

void MainWindow::on_DownpaymentEdit2_editingFinished()
{
    on_totalpriceEdit_editingFinished();
}

void MainWindow::on_DownpaymentEdit3_editingFinished()
{
    on_totalpriceEdit_editingFinished();
}

void MainWindow::on_DownpaymentEdit4_editingFinished()
{
    on_totalpriceEdit_editingFinished();
}

void MainWindow::on_DownpaymentEdit5_editingFinished()
{
    on_totalpriceEdit_editingFinished();
}


//stop non integers and integers over 2000 and edit downpayment to the required minimum percent down

void MainWindow::on_totalpriceEdit_textChanged(const QString &arg1)
{
       ui->totalpriceEdit->setValidator( new QIntValidator(0, 2000, this) );
       double totalprice = ui->totalpriceEdit->text().toInt();
       double percentdown = ui->PercentDownEdit->text().toDouble();
       percentdown = percentdown / 100;
       percentdown = percentdown * totalprice;
       QString downpayment = QString::number(percentdown, 'g', 6);
       ui->DownpaymentEdit->setText(downpayment);
       mainFuncion();

}

void MainWindow::on_totalpriceEdit2_textChanged(const QString &arg1)
{
       ui->totalpriceEdit2->setValidator( new QIntValidator(0, 2000, this) );
       double totalprice = ui->totalpriceEdit2->text().toDouble();
       double percentdown = ui->PercentDownEdit->text().toDouble();
       percentdown = percentdown / 100;
       percentdown = percentdown * totalprice;
       QString downpayment = QString::number(percentdown, 'g', 6);
       ui->DownpaymentEdit2->setText(downpayment);
}

void MainWindow::on_totalpriceEdit3_textChanged(const QString &arg1)
{
       ui->totalpriceEdit3->setValidator( new QIntValidator(0, 2000, this) );
       double totalprice = ui->totalpriceEdit3->text().toDouble();
       double percentdown = ui->PercentDownEdit->text().toDouble();
       percentdown = percentdown / 100;
       percentdown = percentdown * totalprice;
       QString downpayment = QString::number(percentdown, 'g', 6);
       ui->DownpaymentEdit3->setText(downpayment);
}

void MainWindow::on_totalpriceEdit4_textChanged(const QString &arg1)
{
       ui->totalpriceEdit4->setValidator( new QIntValidator(0, 2000, this) );
       double totalprice = ui->totalpriceEdit4->text().toDouble();
       double percentdown = ui->PercentDownEdit->text().toDouble();
       percentdown = percentdown / 100;
       percentdown = percentdown * totalprice;
       QString downpayment = QString::number(percentdown, 'g', 6);
       ui->DownpaymentEdit4->setText(downpayment);
}

void MainWindow::on_totalpriceEdit5_textChanged(const QString &arg1)
{
       ui->totalpriceEdit5->setValidator( new QIntValidator(0, 2000, this) );
       double totalprice = ui->totalpriceEdit5->text().toDouble();
       double percentdown = ui->PercentDownEdit->text().toDouble();
       percentdown = percentdown / 100;
       percentdown = percentdown * totalprice;
       QString downpayment = QString::number(percentdown, 'g', 6);
       ui->DownpaymentEdit5->setText(downpayment);
}

//don't allow downpayment to be greater than total price

void MainWindow::on_DownpaymentEdit_textChanged(const QString &arg1)
{
    int totalpriceEditInput = ui->totalpriceEdit->text().toInt();
    ui->DownpaymentEdit->setValidator( new QIntValidator(0, totalpriceEditInput, this) );
}

void MainWindow::on_DownpaymentEdit2_textChanged(const QString &arg1)
{
    int totalpriceEditInput = ui->totalpriceEdit2->text().toInt();
    ui->DownpaymentEdit2->setValidator( new QIntValidator(0, totalpriceEditInput, this) );
}

void MainWindow::on_DownpaymentEdit3_textChanged(const QString &arg1)
{
    int totalpriceEditInput = ui->totalpriceEdit3->text().toInt();
    ui->DownpaymentEdit3->setValidator( new QIntValidator(0, totalpriceEditInput, this) );
}

void MainWindow::on_DownpaymentEdit4_textChanged(const QString &arg1)
{
    int totalpriceEditInput = ui->totalpriceEdit4->text().toInt();
    ui->DownpaymentEdit4->setValidator( new QIntValidator(0, totalpriceEditInput, this) );
}

void MainWindow::on_DownpaymentEdit5_textChanged(const QString &arg1)
{
    int totalpriceEditInput = ui->totalpriceEdit5->text().toInt();
    ui->DownpaymentEdit5->setValidator( new QIntValidator(0, totalpriceEditInput, this) );
}

//rerun main funcion if you choose to not include the phone so that way it can subtract it from the totals

void MainWindow::on_phoneinclude_stateChanged(int arg1)
{
      mainFuncion();

}

void MainWindow::on_phoneinclude2_stateChanged(int arg1)
{
   mainFuncion();
}

void MainWindow::on_phoneinclude3_stateChanged(int arg1)
{
    mainFuncion();
}

void MainWindow::on_phoneinclude4_stateChanged(int arg1)
{
    mainFuncion();
}

void MainWindow::on_phoneinclude5_stateChanged(int arg1)
{
    mainFuncion();
}

void MainWindow::on_fianancemaxEdit_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_monthlyplanInput_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_monthlyplanInput2_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_monthlyplanInput3_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_monthlyplanInput4_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_monthlyplanInput5_editingFinished()
{
    mainFuncion();
}

//clear buttons
void MainWindow::on_clearallButton_clicked()
{
    ui->DownpaymentEdit->setText("0");
    ui->DownpaymentEdit2->setText("0");
    ui->DownpaymentEdit3->setText("0");
    ui->DownpaymentEdit4->setText("0");
    ui->DownpaymentEdit5->setText("0");

    ui->totalpriceEdit->setText("0");
    ui->totalpriceEdit2->setText("0");
    ui->totalpriceEdit3->setText("0");
    ui->totalpriceEdit4->setText("0");
    ui->totalpriceEdit5->setText("0");

    ui->monthlyplanInput->setText("0");
    ui->monthlyplanInput2->setText("0");
    ui->monthlyplanInput3->setText("0");
    ui->monthlyplanInput4->setText("0");
    ui->monthlyplanInput5->setText("0");

    ui->PercentDownEdit->setText("0");
    ui->fianancemaxEdit->setText("0");



    mainFuncion();
}

void MainWindow::on_clearphonesButton_clicked()
{
    ui->DownpaymentEdit->setText("0");
    ui->DownpaymentEdit2->setText("0");
    ui->DownpaymentEdit3->setText("0");
    ui->DownpaymentEdit4->setText("0");
    ui->DownpaymentEdit5->setText("0");

    ui->totalpriceEdit->setText("0");
    ui->totalpriceEdit2->setText("0");
    ui->totalpriceEdit3->setText("0");
    ui->totalpriceEdit4->setText("0");
    ui->totalpriceEdit5->setText("0");

    ui->monthlyplanInput->setText("0");
    ui->monthlyplanInput2->setText("0");
    ui->monthlyplanInput3->setText("0");
    ui->monthlyplanInput4->setText("0");
    ui->monthlyplanInput5->setText("0");

    mainFuncion();
}

//trigger main function when edited
void MainWindow::on_DPIinput_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_DPIinput2_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_DPIinput3_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_DPIinput4_editingFinished()
{
    mainFuncion();
}

void MainWindow::on_DPIinput5_editingFinished()
{
    mainFuncion();
}

//print function


void MainWindow::on_action_Save_2_triggered()
{
    double totaldownA = ui->totaldownOut->text().toDouble();
    double totalmonthlyA = ui->totalmonthlyOut->text().toDouble();

    double monthlyP = ui->Monthly->text().toDouble();
    double monthlyP2 = ui->Monthly2->text().toDouble();
    double monthlyP3 = ui->Monthly3->text().toDouble();
    double monthlyP4 = ui->Monthly4->text().toDouble();
    double monthlyP5 = ui->Monthly5->text().toDouble();

    double lineacess = ui->monthlyplanInput->text().toDouble();
    double lineacess2 = ui->monthlyplanInput2->text().toDouble();
    double lineacess3 = ui->monthlyplanInput3->text().toDouble();
    double lineacess4 = ui->monthlyplanInput4->text().toDouble();
    double lineacess5 = ui->monthlyplanInput5->text().toDouble();

    double tax = ui->Taxes->text().toDouble();
    double tax2 = ui->Taxes2->text().toDouble();
    double tax3 = ui->Taxes3->text().toDouble();
    double tax4 = ui->Taxes4->text().toDouble();
    double tax5 = ui->Taxes5->text().toDouble();


    double down = ui->DownpaymentEdit->text().toDouble();
    double down2 = ui->DownpaymentEdit2->text().toDouble();
    double down3 = ui->DownpaymentEdit3->text().toDouble();
    double down4 = ui->DownpaymentEdit4->text().toDouble();
    double down5 = ui->DownpaymentEdit5->text().toDouble();

    down = down + tax;
    down2 = down2 + tax2;
    down3 = down3 + tax3;
    down4 = down4 + tax4;
    down5 = down5 + tax5;

    std::ofstream file;
    file.open("QuickQuoteSave.txt");
    file << "Phone1 $" << monthlyP << " Monthly, $" << lineacess << " For Line Acess, $" << down << " Owed now\n" <<
            "Phone2 $" << monthlyP2 << " Monthly, $" << lineacess2 << " For Line Acess, $" << down2 << " Owed now\n" <<
            "Phone3 $" << monthlyP3 << " Monthly, $" << lineacess3 << " For Line Acess, $" << down3 << " Owed now\n" <<
            "Phone4 $" << monthlyP4 << " Monthly, $" << lineacess4 << " For Line Acess, $" << down4 << " Owed now\n" <<
            "Phone5 $" << monthlyP5 << " Monthly, $" << lineacess5 << " For Line Acess, $" << down5 << " Owed now\n" <<
            "\nTotal Monthly Owed is $" << totalmonthlyA << ", Total Owned Now is $" << totaldownA;
    file.close();
}
