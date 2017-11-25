//
//  main.cpp
//  test_run_piece
//
//  Created by Alex Frasca on 11/19/17.
//  Copyright © 2017 Alex Frasca. All rights reserved.
//

#include <iostream>
#include "Piece.cpp"

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
    return 0;
}
