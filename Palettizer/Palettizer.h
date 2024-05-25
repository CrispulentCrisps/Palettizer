// |----------------|
// |   PALETTIZER	|
// |________________|
//
// Written by Crisps
//
// |-------------|
// |   PURPOSE	 |
// |_____________|
//
// The purpose of this library is to allow for palette based control over PNG images in real time.
// 
//	This program allows the user to 
//		*	Import PNG files
//		*	Convert pixel colour information based off of predefined palettes by the user
//		*	Apply those changes to the image in real time when nessecary
//		*	Allow for palette shifting within regions of the palette for artistic effect
//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace Palettizer {

	typedef unsigned char u8;

	//One entry in a palette
	typedef struct pal_entry {
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	};

	//Defines a palette as a series of palette entries of variable size
	typedef std::vector<pal_entry> pal;
	
	//Defines the palette itself alongside functions for messing with it
	class palette {
	public:
		pal entries;//Entire palette
		bool pal_convert(std::ifstream file);//Convert the PNG image to allow for palettisation
		bool pal_shift(pal* palette, int shiftval, int min, int max);//shift the values in the palette from min to max by shiftval amount
		bool pal_update();//update the palette for the image, to be used only once when the palette needs to be updated rather than every frame to save on CPU time
	};

};

/*
Copyright 2024 Crisps

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/