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
	// ���ñ�ͷ
	ui.tableWidget_Sample->setColumnCount(eTablePara_Num);
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_No, new QTableWidgetItem(QStringLiteral("���")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_Barcode, new QTableWidgetItem(QStringLiteral("����")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_PatientName, new QTableWidgetItem(QStringLiteral("����")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_TestStatusAndResult, new QTableWidgetItem(QStringLiteral("״̬/���")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_LiquidType, new QTableWidgetItem(QStringLiteral("����")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_AssayName, new QTableWidgetItem(QStringLiteral("��Ŀ")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_CreateTime, new QTableWidgetItem(QStringLiteral("¼��ʱ��")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_TestID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_OrderID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_SampleID, new QTableWidgetItem(QStringLiteral("����ID")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_Response, new QTableWidgetItem(QStringLiteral("��Ӧ��")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_ResultFlag, new QTableWidgetItem(QStringLiteral("���")));
	ui.tableWidget_Sample->setHorizontalHeaderItem(eTablePara_CuvtteNo, new QTableWidgetItem(QStringLiteral("����")));
	// ���ñ������
	ui.tableWidget_Sample->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ��һ��
	ui.tableWidget_Sample->setSelectionMode(QAbstractItemView::SingleSelection); //����ֻ��ѡ��һ�У����ܶ���ѡ��
	ui.tableWidget_Sample->setEditTriggers(QAbstractItemView::NoEditTriggers);   //����ÿ�����ݲ��ɸ���
	ui.tableWidget_Sample->setAlternatingRowColors(true);   //���ø�һ�б�һ��ɫ������һ��һ��
	ui.tableWidget_Sample->clearContents();
	ui.tableWidget_Sample->verticalHeader()->hide();

	// ���õ�Ԫ������
	ui.tableWidget_Sample->setColumnWidth(eTablePara_No, 50);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_LiquidType, 115);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_AssayName, 80);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_TestStatusAndResult, 130);
	ui.tableWidget_Sample->setColumnWidth(eTablePara_ResultFlag, 60);
	ui.tableWidget_Sample->horizontalHeader()->setStretchLastSection(true);      // ���һ���������
	ui.tableWidget_Sample->setColumnWidth(eTablePara_CuvtteNo, 50);
	ui.tableWidget_Sample->setRowCount(gc_CuvetteNum);   // 4����Ӧ�� 

	for (int iRow = eInstruUnit_CRP_Cuvette1; iRow <= eInstruUnit_CRP_Cuvette4; iRow++)
	{
		QTableWidgetItem *widgetItem = nullptr;

		// ���ÿ������
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
	ui.cbxAgeUnit->addItems(QStringList() << QStringLiteral("��") << QStringLiteral("��") << QStringLiteral("��"));
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