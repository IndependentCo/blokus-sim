//
//  main.cpp
//  test_run_piece
//
//  Created by Alex Frasca on 11/19/17.
//  Copyright © 2017 Alex Frasca. All rights reserved.
//

#include <iostream>
#include "Piece.cpp"
#include "Board.cpp"

using namespace std;

int main() {
    for(int i = 1; i <= 21; i++) {
        Piece test(i, 3);
        test.print();
        cout << endl;
        cout << test.size() << endl;
    }
    Piece test1(16, 4);
    cout << "Starting state." << endl;
    test1.print();
    cout << endl;
    cout << test1.size();
    cout << endl;
    test1.rotate(90);
    cout << "Rotated 90 degrees." << endl;
    test1.print();
    cout << endl;
    cout << test1.size();
    cout << endl;
    test1.rotate(180);
    cout << "Rotated 180 degrees." << endl;
    test1.print();
    cout << endl;
    cout << test1.size();
    cout << endl;
    test1.reflect(true);
    cout << "Reflected over the horizontal." << endl;
    test1.print();
    cout << endl;
    test1.reflect(false);
    cout << "Reflected over the vertical." << endl;
    test1.print();
    cout << endl;
    test1.rotate(270);
    cout << "Rotated 270 degrees." << endl;
    test1.print();
    cout << endl;
    cout << test1.size();
    cout << endl;
    vector<vector<int>> coords = test1.getCoords();
    for(int i=0;i<coords.size();i++){
      vector<int> point = coords[i];
      cout << "(" << point[0] << "," << point[1] <<")" << endl;
    }
    Board board = Board();
    bool isPlaced = false;
    for(int i=0;i<21;i++){
      test1 = Piece(i,2);
      for(int n=0;n<20;n++){
	isPlaced = false;
	for(int m=0;m<20;m++){
	  if(board.isLegalMove(test1,n,m)){
	    board.placePiece(test1,n,m);
	    isPlaced = true;
	    break;
	  }
	}
	if(isPlaced)
	  break;
      }
    }
    board.print();
    

    return 0;
}
