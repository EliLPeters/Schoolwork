// Main file for Data Structures Lab 2 Spring 2018
// Eli Peters

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>

#include "PpmDocument.h"

using namespace std;

enum colors_t { RED = 0, GREEN, BLUE };

// FUNCTIONS FROM PA1
PpmDocument ppmDocumentFromFile(string file_name)
{
	PpmDocument doc{ "P3" };

	//open PPM for file processing
	ifstream source_ppm{ file_name };

	//were we able to open the file?
	if (source_ppm.is_open() == true)
	{
		//grab basic PPM info before starting file
		//loop
		string ppm_type = "";
		string dimensions = "";
		string max_rgb = "";
		getline(source_ppm, ppm_type);
		getline(source_ppm, dimensions);
		getline(source_ppm, max_rgb);

		//convert strings into INTs for PPM document
		int width = 0;
		int height = 0;
		int rgb = 0;
		istringstream dimensions_stream{ dimensions };
		dimensions_stream >> width;
		dimensions_stream >> height;
		rgb = stoi(max_rgb);
		doc = PpmDocument{ ppm_type, width, height, rgb };

		//convert PPM
		while (source_ppm.good() == true)
		{
			int next_value = 0;
			int color_counter = 0;
			int row_counter = 0;
			int col_counter = 0;

			//grab next number irrespective of
			//line
			Pixel temp_pixel{};
			while (source_ppm >> next_value)
			{
				if (color_counter == RED)
				{
					temp_pixel.setRed(next_value);
				}
				else if (color_counter == GREEN)
				{
					temp_pixel.setGreen(next_value);
				}
				else if (color_counter == BLUE)
				{
					//BLUE represents a finished pixel
					temp_pixel.setBlue(next_value);

					//save finished pixel to document
					doc.setPixel(row_counter, col_counter, temp_pixel);

					col_counter++;
					if (col_counter >= doc.getWidth())
					{
						col_counter = 0;
						row_counter++;
					}
				}
				color_counter++;
				color_counter %= 3;
			}
		}
	}
	source_ppm.close();
	return doc;
}
void ppmDocumentToFile(PpmDocument &doc, string file_name)
{
	ofstream output_ppm{ file_name };
	output_ppm << doc.getDocType() << endl;
	output_ppm << doc.getWidth() << " " << doc.getHeight() << endl;
	output_ppm << doc.getMaxRgb() << endl;
	for (int i = 0; i < doc.getHeight(); i++)
	{
		for (int j = 0; j < doc.getWidth(); j++)
		{
			output_ppm << doc.getPixel(i, j).toString() << " ";
		}
		output_ppm << endl;
	}
	output_ppm.close();
}
// END FUNCTIONS FROM PA1

// NEW FUNCTIONS

// fills a PPM document with randomly colored pixels
void chaos(PpmDocument& victim)
{
	srand(time(NULL));
	for (int i = 0; i < victim.getHeight(); i++)
	{
		for (int j = 0; j < victim.getWidth(); j++)
		{
			Pixel& p = victim.getPixel(i, j);
			
			p.setRed(rand() % 255);
			p.setGreen(rand() % 255);
			p.setBlue(rand() % 255);
		}
	}
}

void ppmEncode(PpmDocument& victim, string message)
{
	srand(time(NULL));

	int x = 0;
	int y = 0;



	for (int i = 0; i < message.length(); i++)
	{
		Pixel& p = victim.getPixel(y, x);
		p.setRed(message.at(i));
	}
}

void generateEncodedPPM(string message, string output_name)
{
	PpmDocument doc = PpmDocument();

	doc.setHeight(500);
	doc.setWidth(500);

	chaos(doc);

	ppmEncode(doc, message);
}

// MAIN FUNCTION
int main()
{
	string decrypted_message = "";
	string target_file = "";

	int curr_x = 0;
	int curr_y = 0;

	char curr_char;

	bool terminate = false;

	PpmDocument doc;

	// Learn what file is to be decoded
	cout << "What file would you like to decode?" << endl;
	cin >> target_file;

	doc = ppmDocumentFromFile(target_file);
	
	while (terminate == false)
	{
		Pixel p = doc.getPixel(curr_y, curr_x);

		curr_char = p.getRed();
		decrypted_message += curr_char;

		curr_x = p.getBlue();
		curr_y = p.getGreen();

		if (curr_x == 0 && curr_y == 0)
		{
			terminate = true;
		}
	}

	cout << "The Decrypted message is:" << endl;
	cout << decrypted_message << endl;

	return 0;
}

