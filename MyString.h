#pragma once
class CMyString
{
public:
	CMyString();
	// ��ȯ ������
	explicit CMyString(const char*);
	// ���� ������
	CMyString(const CMyString& rhs);
	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString(void) const;

	void Release(void);
	CMyString& operator=(const CMyString& rhs);

	CMyString(CMyString&& rhs);

	operator char* (void) const
	{
		return m_pszData;
	}

	int GetLength() const;
	int Append(const char* pszParam);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator +=(const CMyString& rhs);

};
