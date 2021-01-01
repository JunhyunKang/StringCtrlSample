#include <cstring>
#include<iostream>
#include <string>
#include "MyString.h"
CMyString::CMyString() : m_pszData(NULL) , m_nLength(0)
{
}

CMyString::CMyString(const char* pszParam)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(pszParam);
}

// ���� ������
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}
CMyString::~CMyString()
{
	// ��ü�� �Ҹ��ϱ� ���� �޸𸮸� �����Ѵ�.
	Release();
}
//
//CMyString::operator char* (void) const
//{
//	return m_pszData;
//}

int CMyString::SetString(const char* pszParam)
{
	Release();
	if (pszParam == NULL)
		return 0;
	m_nLength = strlen(pszParam);
	if (m_nLength == 0)
		return 0;

	m_pszData = new char[m_nLength + 1];
	strcpy_s(m_pszData, sizeof(char) * (m_nLength + 1), pszParam);
	return m_nLength;
}
const char* CMyString::GetString(void) const
{
	return m_pszData;
}
void CMyString::Release(void)
{
	if (m_pszData != NULL)
		delete[] m_pszData;
	// Release �����Ƿ� �ֿ� ��� �ʱ�ȭ
	m_pszData = NULL;
	m_nLength = 0;
}
CMyString& CMyString::operator=(const CMyString& rhs)
{
	// �ڱ� �ڽſ� ���� �����̸� �ƹ��͵� ���� �ʴ´�.
	if (this != &rhs)
		this->SetString(rhs.GetString());
	return *this;
}
//�̵�������
CMyString::CMyString(CMyString &&rhs)
	: m_pszData(NULL), m_nLength(0)
{ 
	std::cout << "CMyString �̵� ������ ȣ��" << std::endl;
	
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;

}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL)
		return 0;
	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;
	if (m_pszData == NULL)
	{
		SetString(pszParam);
		return m_nLength;
	}
	int nLenCur = m_nLength;

	char* pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs)
{

	CMyString strResult(m_pszData);
	strResult.Append(rhs.GetString());
	return strResult;
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
	// TODO: ���⿡ return ���� �����մϴ�.
	Append(rhs.GetString());

	return *this;
}





