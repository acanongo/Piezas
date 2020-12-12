#include "Piezas.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  for (int i =0; i < 3; i ++)
  {
    for ( int j = 0; j < 4; j ++)
    {
      board[i][j] = Blank;
    }
  }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  //make the board have blanks
  for (int i =0; i < BOARD_ROWS; i ++)
  {
    for ( int j = 0; j < BOARD_COLS; j ++)
    {
      board[i][j] = Blank;
    }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  //check if the columnn is full
  int count =0;

  for(int i= 0; i < BOARD_ROWS; i ++)
  {
    if(board[i][column] != Blank)
    {
      count ++;
    }

  }
  //column is full
  if( count == BOARD_ROWS)
  {
    //swithc players before returning
    if(turn == 'X' )
    {
      turn = O;
    }
    else
    {
      turn = X;
    }

  }
  //at this stage the requested piece is valid return the piece
  // find the row of interest first
  int rowPos =0;
  for(int i = 0; i < BOARD_ROWS; i++)
  {
    if( board[i][column] != Blank)
    {
      rowPos ++;
    }
  }
  //swithc players before returning
  if(turn == 'X' )
  {
    turn = O;
  }
  else
  {
    turn = X;
  }

  return this->board[rowPos][column];

}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row > BOARD_ROWS || column > BOARD_COLS)
    {
      return Blank;

    }
    if(this->board[row][column] == Blank)
    {
      return Blank;
    }

    return this->board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  //check to see if any cell is empty
  for(int i = 0; i < BOARD_ROWS; i++)
  {
    for(int j=0; j < BOARD_COLS; j++)
    {
      if(board[i][j] == Blank)
      {
        return Invalid;
      }
    }
  }

  int Xcount =0;
  int Ycount = 0;
  std::string temp = "";
  std::string curWinner;
  int total_y  =0;
  int total_x = 0;
  int finalCount;
  //at this stage the board is full return the winner

  for(int  i = 0; i < BOARD_ROWS -1; i ++)
  {
    if(board[i][0] == X && (board[i+1][0] == X))
    {
      Xcount ++;
      total_x ++;
    }
    else if(board[i][0] == O && (board[i+1][0] == O))
    {
      Ycount++;
      total_y ++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
    finalCount = Xcount;
  }
  else
  {
    temp = "Y";
    finalCount = Ycount;
  }
  int currCount = 0;
  curWinner = temp;
  currCount = finalCount;



  //
  Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_ROWS -1; i ++)
  {
    if(board[i][1] == X && (board[i+1][1] == X))
    {
      Xcount ++;
    }
    else if(board[i][1] == O && (board[i+1][1] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
    finalCount = Xcount;
  }
  else
  {
    temp = "Y";
    finalCount = Ycount;
  }

  if(curWinner < temp)
  {
    curWinner = temp;
  }
  //
  Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_ROWS -1; i ++)
  {
    if(board[i][2] == X && (board[i+1][2] == X))
    {
      Xcount ++;
    }
    else if(board[i][2] == O && (board[i+1][2] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
  }
  else
  {
    temp = "Y";
    finalCount = Ycount;
  }

  if(curWinner < temp)
  {
    curWinner = temp;
  }
  std::string rowWinner = curWinner;

  // colum
  Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_COLS -1; i ++)
  {
    if(board[0][i] == X && (board[0][i+1] == X))
    {
      Xcount ++;
    }
    else if(board[0][i+1] == O && (board[0][i+1] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
    finalCount = Xcount;
  }
  else
  {
    temp = "Y";
    finalCount = Ycount;
  }

  if(curWinner < temp)
  {
    curWinner = temp;
    currCount = finalCount;
  }

  //
  Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_COLS-1; i ++)
  {
    if(board[1][i] == X && (board[1][i+1] == X))
    {
      Xcount ++;
    }
    else if(board[1][i] == O && (board[1][i+1] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
  }
  else
  {
    temp = "Y";
  }

  if(curWinner < temp)
  {
    curWinner = temp;
  }

  //Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_ROWS -1; i ++)
  {
    if(board[2][i] == X && (board[2][i+1] == X))
    {
      Xcount ++;
    }
    else if(board[2][i] == O && (board[i+1][0] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
  }
  else
  {
    temp = "Y";
  }

  if(curWinner < temp)
  {
    curWinner = temp;
  }

  //Xcount =0;
  Ycount =0;
  for(int  i = 0; i < BOARD_ROWS -1; i ++)
  {
    if(board[3][i] == X && (board[3][i+1] == X))
    {
      Xcount ++;
    }
    else if(board[3][i] == O && (board[3][i+1] == O))
    {
      Ycount++;
    }
  }

  if(Xcount > Ycount)
  {
    temp = "X";
  }
  else
  {
    temp = "Y";
  }

  if(curWinner < temp)
  {
    curWinner = temp;
  }

  if(curWinner == "X")
  {
    return X;

  }

  return O;

}
