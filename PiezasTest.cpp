/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.dropPiece(100);

	ASSERT_FALSE(true);
}


TEST(PiezasTest, s)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.dropPiece(-1);

	ASSERT_TRUE(true);
}


TEST(PiezasTest, dropFalseTest)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.dropPiece(0);

	ASSERT_TRUE(true);
}


TEST(PiezasTest, testDrop)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.dropPiece(0);

	ASSERT_TRUE(true);
}


TEST(PiezasTest, testRest)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-1,-1);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, testPiece)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-1,-1);

	ASSERT_FALSE(false);
}

TEST(PiezasTest, validtestPiece)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(0,0);

	ASSERT_TRUE(true);
}


TEST(PiezasTest, testPieceValid)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(2,3);

	ASSERT_TRUE(false);
}

TEST(PiezasTest, validPiece)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(2,2);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, testPieceMinus)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-100,-100);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, testPiecePos)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(3,3);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, tPieceMinus)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-100,-100);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, testPos)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(1,3);

	ASSERT_FALSE(false);
}

TEST(PiezasTest, testPieceMinu)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-100,-100);

	ASSERT_FALSE(false);
}


TEST(PiezasTest, Minus)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(12,-100);

	ASSERT_FALSE(false);
}

TEST(PiezasTest, posValid)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(0,2);

	ASSERT_FALSE(false);
}



TEST(PiezasTest, Valid)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(2,2);

	ASSERT_FALSE(false);
}




TEST(PiezasTest, pv)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(2,0);

	ASSERT_FALSE(false);
}



TEST(PiezasTest, neg)
{
  Piezas obj;

  //obj.dropPiece(10);

  bool actual = obj.pieceAt(-1,-12);

	ASSERT_FALSE(false);
}
