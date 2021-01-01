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

// 복사 생성자
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}
CMyString::~CMyString()
{
	// 객체가 소멸하기 전에 메모리를 해제한다.
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
	// Release 했으므로 주요 멤버 초기화
	m_pszData = NULL;
	m_nLength = 0;
}
CMyString& CMyString::operator=(const CMyString& rhs)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &rhs)
		this->SetString(rhs.GetString());
	return *this;
}
//이동생성자
CMyString::CMyString(CMyString &&rhs)
	: m_pszData(NULL), m_nLength(0)
{ 
	std::cout << "CMyString 이동 생성자 호출" << std::endl;
	
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
	// TODO: 여기에 return 문을 삽입합니다.
	Append(rhs.GetString());

	return *this;
}





