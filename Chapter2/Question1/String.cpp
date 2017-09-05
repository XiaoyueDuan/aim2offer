# str1=str2;
# str1=str1;
# str1=str2=str3;

#include <cstring>
#include <stdio.h>

class CMyString
{
public:
	CMyString(char *pData = nullptr)
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy_s(m_pData, strlen(pData)+1, pData);
	}
	CMyString(const CMyString &str)
	{
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy_s(m_pData, strlen(str.m_pData)+1, str.m_pData);
	}
	~CMyString(void)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}

	//CMyString& operator =(const CMyString &cstr)
	//{
	//	if (this == &cstr)
	//		return *this;

	//	delete[]m_pData;
	//	m_pData = nullptr;
	//	m_pData = new char[strlen(cstr.m_pData) + 1];
	//	strcpy_s(m_pData, strlen(cstr.m_pData) + 1, cstr.m_pData);
	//	return *this;
	//}

	CMyString& operator =(const CMyString &str)
	{
		if (this != &str)
		{
			CMyString tmpStr(str);

			char *tmpHead = m_pData;
			m_pData = tmpStr.m_pData;
			tmpStr.m_pData = tmpHead;
		}
		return *this;
	}

private:
	char *m_pData;
};

int main()
{
	CMyString str1("1");
	CMyString str2("2");
	CMyString str3("3");

	str1 = str1;
	str1 = str2 = str3;

	return 0;
}