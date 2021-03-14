#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Student\oop2.6\oop2.6\Long.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest26
{
	TEST_CLASS(UnitTest26)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Long a;
			int t;
			t = a.Diff_2(1000, 7);
			Assert::AreEqual(t, 993);
		}
	};
}
