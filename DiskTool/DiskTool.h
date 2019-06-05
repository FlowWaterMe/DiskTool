#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DiskTool.h"
#include "DiskItemView.h"
static const QString st_sUnknown = QStringLiteral("未知");
static const QString st_sMan = QStringLiteral("男");
static const QString st_sWoman = QStringLiteral("女");
class DiskTool : public QMainWindow
{
	Q_OBJECT

public:
	DiskTool(QWidget *parent = Q_NULLPTR);
	~DiskTool();
	void InitUITableWidget();
	void InitUIPatientInfo();
	void InitConnect(bool bisconnect);
private:
	Ui::DiskToolClass ui;

private slots:
	void slotNofityInfoToTable(SItemRectInfo sInfo);
	void on_btnmodif_clicked();
	void on_btnsave_clicked();
};

enum ETablePara
{
	eTablePara_No = 0,
	eTablePara_CuvtteNo,
	eTablePara_LiquidType,
	eTablePara_AssayName,
	eTablePara_TestStatusAndResult,
	eTablePara_ResultFlag,
	eTablePara_PatientName,
	eTablePara_CreateTime,
	eTablePara_Response,
	eTablePara_TestID,
	eTablePara_OrderID,
	eTablePara_SampleID,
	eTablePara_Barcode,
	eTablePara_Num,
};
enum EInstruUnit
{
	//CRP部件
	eInstruUnit_CRP_Cuvette1 = 0,   // 反应杯1
	eInstruUnit_CRP_Cuvette2,	    // 反应杯2
	eInstruUnit_CRP_Cuvette3,	    // 反应杯3
	eInstruUnit_CRP_Cuvette4,	    // 反应杯4
};

const unsigned int gc_iCRP_ADNum = 296;   // 296
const unsigned int gc_CuvetteNum = eInstruUnit_CRP_Cuvette4 - eInstruUnit_CRP_Cuvette1 + 1;