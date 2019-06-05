#include "DiskTool.h"

DiskTool::DiskTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitUITableWidget();
	InitUIPatientInfo();
	InitConnect(true);
}

DiskTool::~DiskTool()
{
	InitConnect(false);
}

void DiskTool::InitUITableWidget()
{
	// 设置表头
	ui.tableWidget_Sample->setColumnCount(eTablePara_Num);
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_No, new QTableWidgetItem(QStringLiteral("编号")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_Barcode, new QTableWidgetItem(QStringLiteral("条码")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_PatientName, new QTableWidgetItem(QStringLiteral("姓名")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_TestStatusAndResult, new QTableWidgetItem(QStringLiteral("状态/结果")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_LiquidType, new QTableWidgetItem(QStringLiteral("类型")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_AssayName, new QTableWidgetItem(QStringLiteral("项目")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_CreateTime, new QTableWidgetItem(QStringLiteral("录入时间")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_TestID, new QTableWidgetItem(QStringLiteral("测试ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_OrderID, new QTableWidgetItem(QStringLiteral("订单ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_SampleID, new QTableWidgetItem(QStringLiteral("样本ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_Response, new QTableWidgetItem(QStringLiteral("反应度")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_ResultFlag, new QTableWidgetItem(QStringLiteral("标记")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_CuvtteNo, new QTableWidgetItem(QStringLiteral("杯号")));
	// 设置表格属性
	ui.tableWidget_Sample->setSelectionBehavior(QAbstractItemView::SelectRows);  //单击选择一行
	ui.tableWidget_Sample->setSelectionMode(QAbstractItemView::SingleSelection); //设置只能选择一行，不能多行选中
	ui.tableWidget_Sample->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置每行内容不可更改
	ui.tableWidget_Sample->setAlternatingRowColors(true);   //设置隔一行变一颜色，即：一灰一白
	ui.tableWidget_Sample->clearContents();
	ui.tableWidget_Sample->verticalHeader()->hide();

	// 设置单元格属性
	ui.tableWidget_Sample->setColumnWidth(eTablePara_No, 50);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_LiquidType, 115);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_AssayName, 80);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_TestStatusAndResult, 130);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_ResultFlag, 60);
	ui.tableWidget_Sample->horizontalHeader()->setStretchLastSection(true);      // 最后一列填满表格
	ui.tableWidget_Sample->setColumnWidth(eTablePara_CuvtteNo, 50);
	ui.tableWidget_Sample->setRowCount(gc_CuvetteNum);   // 4个反应杯 

	for (int iRow = eInstruUnit_CRP_Cuvette1; iRow <= eInstruUnit_CRP_Cuvette4; iRow++)
	{
		QTableWidgetItem *widgetItem = nullptr;

		// 清空每列数据
		for (int iColumn = eTablePara_No; iColumn < eTablePara_Num; iColumn++)
		{
			widgetItem = new QTableWidgetItem(QTableWidgetItem::Type);
			widgetItem->setText("");
			widgetItem->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_Sample->setItem(iRow, iColumn, widgetItem);
		}

	}
}

void DiskTool::InitUIPatientInfo()
{
	ui.cbxAgeUnit->setView(new QListView());
	ui.cbxAgeUnit->addItems(QStringList() << QStringLiteral("岁") << QStringLiteral("月") << QStringLiteral("天"));
	ui.cbxAgeUnit->setCurrentIndex(0);

	ui.cbxGender->setView(new QListView());
	ui.cbxGender->addItems(QStringList() << st_sUnknown << st_sMan << st_sWoman);
	ui.cbxGender->setCurrentIndex(0);

	ui.edtSampleNo->setEnabled(false);
	ui.spinBoxPcv->setValue(40);
	ui.spinBoxPcv->setDecimals(1);
	ui.spinBoxPcv->setSingleStep(0.5);

}
void DiskTool::InitConnect(bool bisconnect)
{
	qRegisterMetaType<SItemRectInfo>("SItemRectInfo");
	if (bisconnect == true)
	{
		connect(ui.widget_Diskview, SIGNAL(signalNofityInfoToTable(SItemRectInfo)), this, SLOT(slotNofityInfoToTable(SItemRectInfo)));
	}
	else
	{
		disconnect(ui.widget_Diskview, SIGNAL(signalNofityInfoToTable(SItemRectInfo)), this, SLOT(slotNofityInfoToTable(SItemRectInfo)));
	}
}
void DiskTool::slotNofityInfoToTable(SItemRectInfo sInfo)
{
	qDebug() << "slotNofityInfoToTable be active";
	if (sInfo.m_IdNum < 0)
	{
		return;
	}
	ui.edtSampleNo->setText(QString::number(sInfo.m_IdNum));
}

void DiskTool::on_btnmodif_clicked()
{
	qDebug() << "on_btnmodif_clicked be actived";
}

void DiskTool::on_btnsave_clicked()
{
	qDebug() << "on_btnmodif_clicked be actived";
}