#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void on_totalpriceEdit_editingFinished();
    void on_totalpriceEdit2_editingFinished();
    void on_totalpriceEdit3_editingFinished();
    void on_totalpriceEdit4_editingFinished();
    void on_totalpriceEdit5_editingFinished();

    void on_DownpaymentEdit_editingFinished();
    void on_DownpaymentEdit2_editingFinished();
    void on_DownpaymentEdit3_editingFinished();
    void on_DownpaymentEdit4_editingFinished();
    void on_DownpaymentEdit5_editingFinished();

    void mainFuncion();

    void on_totalpriceEdit_textChanged(const QString &arg1);
    void on_totalpriceEdit2_textChanged(const QString &arg1);
    void on_totalpriceEdit3_textChanged(const QString &arg1);
    void on_totalpriceEdit4_textChanged(const QString &arg1);
    void on_totalpriceEdit5_textChanged(const QString &arg1);

    void on_DownpaymentEdit_textChanged(const QString &arg1);
    void on_DownpaymentEdit2_textChanged(const QString &arg1);
    void on_DownpaymentEdit3_textChanged(const QString &arg1);
    void on_DownpaymentEdit4_textChanged(const QString &arg1);
    void on_DownpaymentEdit5_textChanged(const QString &arg1);


    void on_phoneinclude_stateChanged(int arg1);
    void on_phoneinclude2_stateChanged(int arg1);
    void on_phoneinclude3_stateChanged(int arg1);
    void on_phoneinclude4_stateChanged(int arg1);
    void on_phoneinclude5_stateChanged(int arg1);

    void on_fianancemaxEdit_editingFinished();

    void on_monthlyplanInput_editingFinished();
    void on_monthlyplanInput2_editingFinished();
    void on_monthlyplanInput3_editingFinished();
    void on_monthlyplanInput4_editingFinished();
    void on_monthlyplanInput5_editingFinished();

    void on_clearallButton_clicked();

    void on_clearphonesButton_clicked();

    void on_DPIinput_editingFinished();
    void on_DPIinput2_editingFinished();
    void on_DPIinput3_editingFinished();
    void on_DPIinput4_editingFinished();
    void on_DPIinput5_editingFinished();

    void on_action_Save_2_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
