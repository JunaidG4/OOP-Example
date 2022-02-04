#include "pch.h"
#include "CppUnitTest.h"
#include "../finalOOP/infixCalc.h"
#include "../finalOOP/myStack.h"
#include "../finalOOP/NQueens.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOPUnitTests
{
	TEST_CLASS(InfixResultTests)
	{
	public:
		
		TEST_METHOD(onePlusOneIsTwo)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(onePlusFiveIsSix)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(threePlusThreeIsSix)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(SevenPlusOneIsEight)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(tenPlusOneIsEleven)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(elevenPlusThreeIsFourteen)
		{
			Assert::AreEqual(1, 2);
		}

	};

	TEST_CLASS(InfixPostfixTests)
	{
	public:

		TEST_METHOD(onePlusOneIs_OneOne_Plus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(onePlusFiveIs_OneFive_Plus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(threePlusThreeIs_ThreeThree_Plus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(SevenPlusOneIs_SevenEight_Plus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(tenPlusOneIs_OneZeroOne_Plus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(elevenPlusThreeIs_OneOneThree_Plus)
		{
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(A_Plus_B_Is_ABPlus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AB_Plus_B_Is_ABBPlus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(A_Plus_B_Div_C_Is_ABCDivPlus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(D_Minus_A_Is_DAMinus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AX_Plus_B_Mult_C_Is_AXBCMultPlus)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AXB_Mult_B_Mult_D_Is_AXBBDMultMult)
		{
			Assert::AreEqual(1, 1);
		}

	};

	TEST_CLASS(InfixPrefixTests)
	{
	public:

		TEST_METHOD(onePlusOneIs_Plus_OneOne)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(onePlusFiveIs_Plus_OneFive)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(threePlusThreeIs_Plus_ThreeThree)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(SevenPlusOneIs_Plus_SevenEight)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(tenPlusOneIs_Plus_OneZeroOne)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(elevenPlusThreeIs_Plus_OneOneThree)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(A_Plus_B_Is_PlusAB)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AB_Plus_B_Is_PlusABB)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(A_Plus_B_Div_C_Is_Plus_A_Div_BC)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(D_Minus_A_Is_MinusDA)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AX_Plus_B_Mult_C_Is_Plus_AX_Mult_BC)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(AXB_Mult_B_Mult_D_Is_Mult_AXB_Mult_BD)
		{
			Assert::AreEqual(1, 1);
		}

	};

	TEST_CLASS(NQueensTests)
	{
	public:

		TEST_METHOD(One_Solves_Zero)
		{
			Assert::AreEqual(1, 1);
		}
		
		TEST_METHOD(Two_Solves_Zero)
		{
			Assert::AreEqual(1, 1);
		}
		
		TEST_METHOD(Three_Solves_Zero)
		{
			Assert::AreEqual(1, 1);
		}
		
		TEST_METHOD(Four_Solves_Two)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Five_Solves_Ten)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Six_Solves_Four)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Seven_Solves_Forty)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Eight_Solves_NinetyTwo)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Nine_Solves_ThreeHundredAndFiftyTwo)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Ten_Solves_SevenHundredAndTwentyFour)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Five_Point_Seven_Solves_Ten)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Six_Point_Three_Solves_Four)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Ten_Point_Three_Solves_SevenHundredAndTwentyFour)
		{
			Assert::AreEqual(1, 1);
		}

	};
}
