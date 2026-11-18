#include "envgui.h"
#include "ui_envgui.h"

#include <QWidget>
#include <QDebug>
#include <QTableWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QProcess>
#include <QProcessEnvironment>
#include <QMessageBox>
#include <QLineEdit>
#include <QDialog>

EnvGui::EnvGui(QWidget *parent) : QWidget(parent), ui(new Ui::EnvGui), process(new QProcess(this)) {
    ui->setupUi(this);
    QStringList headers = {"Key", "Value"};

    ui->tableWidgetEnvVars->setHorizontalHeaderLabels(headers);
    connect(ui->pushButtonSelectExecutable, &QPushButton::clicked, this, &EnvGui::selectExecutable);
    connect(ui->pushButtonAddEnvVariable, &QPushButton::clicked, this, &EnvGui::addEnvironmentVariable);
    connect(ui->pushButtonLaunchApp, &QPushButton::clicked, this, &EnvGui::launchApplication);
}

EnvGui::~EnvGui()
{
    delete ui;
}

void EnvGui::selectExecutable() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "All Files (*);;Executable Files (*.exe)");
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "No Executable", "Please select an executable.");
        return;
    }
    ui->labelSelectedExecutablePath->setText("Selected executable: " + fileName);

}

void EnvGui::addEnvironmentVariable() {
    QString key = "";
    QString value = "";

    // Opens another window for key value pairs
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Edit Variable");
    dialog->resize(200, 200);

    QVBoxLayout *layout = new QVBoxLayout;
    dialog->setLayout(layout);

    auto* keyEdit = new QLineEdit(dialog);
    auto* valueEdit = new QLineEdit(dialog);
    keyEdit->setPlaceholderText("Enter variable name");
    valueEdit->setPlaceholderText("Enter value");

    auto* okButton = new QPushButton("OK", dialog);
    okButton->setEnabled(false); // Enable after validation

    connect(keyEdit, &QLineEdit::textChanged, this, [=]() {
        bool valid = !keyEdit->text().trimmed().isEmpty();
        okButton->setEnabled(valid);
    });
    connect(okButton, &QPushButton::clicked, this, [=]() {
        QString key = keyEdit->text();    // Get the key from QLineEdit
        QString value = valueEdit->text(); // Get the value from QLineEdit

        // Check if both the key and value are not empty
        if (!key.isEmpty() && !value.isEmpty()) {
            int row = ui->tableWidgetEnvVars->rowCount();  // Get the current row count
            ui->tableWidgetEnvVars->insertRow(row);        // Insert a new row in the table

            // Insert the key and value into the table
            ui->tableWidgetEnvVars->setItem(row, 0, new QTableWidgetItem(key));   // Column 0 for key
            ui->tableWidgetEnvVars->setItem(row, 1, new QTableWidgetItem(value)); // Column 1 for value
        }
        dialog->close();
    });

    layout->addWidget(keyEdit);
    layout->addWidget(valueEdit);
    layout->addWidget(okButton);

    dialog->show();
}

void EnvGui::launchApplication() {
    QString selectedExecutable = ui->labelSelectedExecutablePath->text();
    if (selectedExecutable.isEmpty()) {
        QMessageBox::warning(this, "No Executable", "Please select an executable to run.");
        return;
    }

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

    for (int row = 0; row < ui->tableWidgetEnvVars->rowCount(); ++row) {
        QString key = ui->tableWidgetEnvVars->item(row, 0)->text();
        QString value = ui->tableWidgetEnvVars->item(row, 1)->text();

        if (!key.isEmpty() && !value.isEmpty()) {
            env.insert(key, value);
        }
    }

    process->start(selectedExecutable);

    connect(process, &QProcess::readyReadStandardOutput, [this]() { ui->textEditOutput->append(process->readAllStandardOutput()); });

    connect(process, &QProcess::readyReadStandardError, [this]() { ui->textEditOutput->append(process->readAllStandardError()); });
}