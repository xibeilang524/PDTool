﻿#include "iec103asdu38data.h"

IEC103Asdu38Data::IEC103Asdu38Data()
{
	vti = 0;
	qds = 0;
}

IEC103Asdu38Data::~IEC103Asdu38Data()
{

}

bool IEC103Asdu38Data::handle(const QByteArray& buff)
{
	vti = *(buff.data() + len);
	mText.append(CharToHexStr(buff.data() + len) + "\t" + vtiToText_iec103(vti)  + "\r\n");
	len++;

	qds = *(buff.data() + len);
	mText.append(CharToHexStr(buff.data() + len) + "\t品质位:" + ivToText(qds) + "   " + ntToText(qds) + "   " + sbToText(qds) + "   " + blToText(qds) + "   " + ovToText(qds) + "\r\n");
	len++;

	mText.append("-----------------------------------------------------------------------------------------------\r\n");
	if(len > buff.length())
	{
		error = QString("\"%1\" %2 [%3行]\r\n%4\r\n").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__).arg(QString("出错！解析所需报文长度(%1)比实际报文长度(%2)长").arg(len).arg(buff.length()));
		return false;
	}
	return true;
}

bool IEC103Asdu38Data::createData(IECDataConfig& config)
{
	error = QString("\"%1\" %2 [%3行]\r\n%4\r\n").arg(__FILE__).arg(__FUNCTION__).arg(__LINE__).arg("出错！生成报文失败");
	return false;
}
