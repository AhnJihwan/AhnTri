unsigned char font[253][8] = {
	//Borrowed from romfont
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E},
	{0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E},
	{0x36, 0x7F, 0x7F, 0x7F, 0x3E, 0x1C, 0x08, 0x00},
	{0x08, 0x1C, 0x3E, 0x7F, 0x3E, 0x1C, 0x08, 0x00},
	{0x18, 0x3C, 0x3C, 0xE7, 0xE7, 0xDB, 0x18, 0x3C},
	{0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0xDB, 0x18, 0x3C},
	{0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00},
	{0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF},
	{0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00},
	{0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF},
	{0xF0, 0xE0, 0xF0, 0xBE, 0x33, 0x33, 0x33, 0x1E},
	{0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18},
	{0xFC, 0xCC, 0xFC, 0x0C, 0x0C, 0x0E, 0x0F, 0x07},
	{0xFE, 0xC6, 0xFE, 0xC6, 0xC6, 0xE6, 0x67, 0x03},
	{0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99},
	{0x01, 0x07, 0x1F, 0x7F, 0x1F, 0x07, 0x01, 0x00},
	{0x40, 0x70, 0x7C, 0x7F, 0x7C, 0x70, 0x40, 0x00},
	{0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18},
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00},
	{0xFE, 0xDB, 0xDB, 0xDE, 0xD8, 0xD8, 0xD8, 0x00},
	{0x7C, 0xC6, 0x1C, 0x36, 0x36, 0x1C, 0x33, 0x1E},
	{0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00},
	{0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0xFF},
	{0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00},
	{0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00},
	{0x00, 0x18, 0x30, 0x7F, 0x30, 0x18, 0x00, 0x00},
	{0x00, 0x0C, 0x06, 0x7F, 0x06, 0x0C, 0x00, 0x00},
	{0x00, 0x00, 0x03, 0x03, 0x03, 0x7F, 0x00, 0x00},
	{0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00},
	{0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00},
	{0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x0C, 0x1E, 0x1E, 0x0C, 0x0C, 0x00, 0x0C, 0x00},
	{0x36, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00},
	{0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00},
	{0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00},
	{0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00},
	{0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00},
	{0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00},
	{0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},
	{0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06},
	{0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00},
	{0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00},
	{0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00},
	{0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00},
	{0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00},
	{0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00},
	{0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00},
	{0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00},
	{0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00},
	{0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00},
	{0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00},
	{0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00},
	{0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00},
	{0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06},
	{0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00},
	{0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00},
	{0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00},
	{0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00},
	{0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00},
	//End of Borrowing
	//Start of AhnTri-Maize font(Copyright 2021 AhnTri Project X Maize Project)
	//Font AhnTri(Large_alphabet)
	{0x18, 0x3C, 0x66, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3},
	{0x3F, 0x46, 0x46, 0x3E, 0x46, 0x46, 0x46, 0x3E},
	{0x18, 0x7E, 0x42, 0x03, 0x01, 0x41, 0x63, 0x3E},
	{0x3F, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x3E},
	{0xFE, 0x86, 0x46, 0x7E, 0x46, 0x06, 0x86, 0xFE},
	{0x7E, 0x46, 0x06, 0x7E, 0x06, 0x06, 0x06, 0x0E},
	{0x3C, 0x66, 0x03, 0xF3, 0x63, 0x66, 0x7C, 0x00},
	{0xE7, 0x42, 0x42, 0x7E, 0x7E, 0x42, 0x42, 0xE7},
	{0x7E, 0x5A, 0x18, 0x18, 0x18, 0x18, 0x5A, 0x7E},
	{0x7E, 0x5A, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x06},
	{0xC7, 0x66, 0x36, 0x0E, 0x1E, 0x36, 0x66, 0xC7},
	{0x07, 0x06, 0x06, 0x06, 0x06, 0x86, 0xFF, 0xFF},
	{0xC3, 0xE7, 0xBD, 0x99, 0x99, 0x99, 0x81, 0xC3},
	{0xE7, 0x4E, 0x5E, 0x5A, 0x72, 0x62, 0x62, 0xC7},
	{0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x08},
	{0x1F, 0x30, 0x22, 0x32, 0x1E, 0x02, 0x02, 0x07},
	{0x1E, 0x63, 0x63, 0x63, 0x6B, 0x1E, 0x38, 0x70},
	{0x1F, 0x32, 0x22, 0x22, 0x3E, 0x1A, 0x32, 0x67},
	{0x1E, 0x73, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x0C},
	{0xFF, 0x99, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C},
	{0xE7, 0x42, 0x42, 0x42, 0x42, 0x42, 0xFC, 0xFC},
	{0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x66, 0x3C, 0x18},
	{0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x41},
	{0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0xC3},	//Large Z
	//End of AT font
	//Borrowing starts again
	{0xE7, 0x42, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x3C},
	{0xFF, 0xC1, 0x60, 0x10, 0x3C, 0x08, 0x86, 0xFF},
	{0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00},
	{0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00},
	{0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00},
	{0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},
	{0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00},
	{0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00},
	{0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00},
	{0x38, 0x30, 0x30, 0x3E, 0x33, 0x33, 0x6E, 0x00},
	{0x00, 0x00, 0x1E, 0x33, 0x3F, 0x03, 0x1E, 0x00},
	{0x1C, 0x36, 0x06, 0x0F, 0x06, 0x06, 0x0F, 0x00},
	{0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F},
	{0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00},
	{0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},
	{0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E},
	{0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00},
	{0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},
	{0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00},
	{0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00},
	{0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00},
	{0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F},
	{0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78},
	{0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00},
	{0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00},
	{0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00},
	{0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00},
	{0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00},
	{0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00},
	{0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00},
	{0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F},
	{0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00},
	{0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00},
	{0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},
	{0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00},
	{0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x08, 0x1C, 0x36, 0x63, 0x63, 0x7F, 0x00},
	{0x1E, 0x33, 0x03, 0x03, 0x33, 0x1E, 0x30, 0x1E},
	{0x00, 0x33, 0x00, 0x33, 0x33, 0x33, 0x7E, 0x00},
	{0x38, 0x00, 0x1E, 0x33, 0x3F, 0x03, 0x1E, 0x00},
	{0x7E, 0xC3, 0x3C, 0x60, 0x7C, 0x66, 0xFC, 0x00},
	{0x33, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x7E, 0x00},
	{0x07, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x7E, 0x00},
	{0x0C, 0x0C, 0x1E, 0x30, 0x3E, 0x33, 0x7E, 0x00},
	{0x00, 0x00, 0x1E, 0x03, 0x03, 0x1E, 0x30, 0x1C},
	{0x7E, 0xC3, 0x3C, 0x66, 0x7E, 0x06, 0x3C, 0x00},
	{0x33, 0x00, 0x1E, 0x33, 0x3F, 0x03, 0x1E, 0x00},
	{0x07, 0x00, 0x1E, 0x33, 0x3F, 0x03, 0x1E, 0x00},
	{0x33, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},
	{0x3E, 0x63, 0x1C, 0x18, 0x18, 0x18, 0x3C, 0x00},
	{0x07, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},
	{0x63, 0x1C, 0x36, 0x63, 0x7F, 0x63, 0x63, 0x00},
	{0x0C, 0x0C, 0x00, 0x1E, 0x33, 0x3F, 0x33, 0x00},
	{0x38, 0x00, 0x3F, 0x06, 0x1E, 0x06, 0x3F, 0x00},
	{0x00, 0x00, 0xFE, 0x30, 0xFE, 0x33, 0xFE, 0x00},
	{0x7C, 0x36, 0x33, 0x7F, 0x33, 0x33, 0x73, 0x00},
	{0x1E, 0x33, 0x00, 0x1E, 0x33, 0x33, 0x1E, 0x00},
	{0x00, 0x33, 0x00, 0x1E, 0x33, 0x33, 0x1E, 0x00},
	{0x00, 0x07, 0x00, 0x1E, 0x33, 0x33, 0x1E, 0x00},
	{0x1E, 0x33, 0x00, 0x33, 0x33, 0x33, 0x7E, 0x00},
	{0x00, 0x07, 0x00, 0x33, 0x33, 0x33, 0x7E, 0x00},
	{0x00, 0x33, 0x00, 0x33, 0x33, 0x3E, 0x30, 0x1F},
	{0x63, 0x1C, 0x36, 0x63, 0x63, 0x36, 0x1C, 0x00},
	{0x33, 0x00, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x00},
	{0x18, 0x18, 0x7E, 0x03, 0x03, 0x7E, 0x18, 0x18},
	{0x1C, 0x36, 0x26, 0x0F, 0x06, 0x67, 0x3F, 0x00},
	{0x33, 0x33, 0x1E, 0x3F, 0x0C, 0x3F, 0x0C, 0x0C},
	{0x1F, 0x33, 0x33, 0x5F, 0x63, 0xF3, 0x63, 0xE3},
	{0x70, 0xD8, 0x18, 0x3C, 0x18, 0x18, 0x1B, 0x0E},
	{0x38, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x7E, 0x00},
	{0x1C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},
	{0x00, 0x38, 0x00, 0x1E, 0x33, 0x33, 0x1E, 0x00},
	{0x00, 0x38, 0x00, 0x33, 0x33, 0x33, 0x7E, 0x00},
	{0x00, 0x1F, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x00},
	{0x3F, 0x00, 0x33, 0x37, 0x3F, 0x3B, 0x33, 0x00},
	{0x3C, 0x36, 0x36, 0x7C, 0x00, 0x7E, 0x00, 0x00},
	{0x1C, 0x36, 0x36, 0x1C, 0x00, 0x3E, 0x00, 0x00},
	{0x0C, 0x00, 0x0C, 0x06, 0x03, 0x33, 0x1E, 0x00},
	{0x00, 0x00, 0x00, 0x3F, 0x03, 0x03, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x3F, 0x30, 0x30, 0x00, 0x00},
	{0xC3, 0x63, 0x33, 0x7B, 0xCC, 0x66, 0x33, 0xF0},
	{0xC3, 0x63, 0x33, 0xDB, 0xEC, 0xF6, 0xF3, 0xC0},
	{0x18, 0x00, 0x18, 0x18, 0x3C, 0x3C, 0x18, 0x00},
	{0x00, 0xCC, 0x66, 0x33, 0x66, 0xCC, 0x00, 0x00},
	{0x00, 0x33, 0x66, 0xCC, 0x66, 0x33, 0x00, 0x00},
	{0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11},
	{0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55},
	{0xDB, 0xEE, 0xDB, 0x77, 0xDB, 0xEE, 0xDB, 0x77},
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18},
	{0x6C, 0x6C, 0x6C, 0x6C, 0x6F, 0x6C, 0x6C, 0x6C},
	{0x00, 0x00, 0x00, 0x00, 0x7F, 0x6C, 0x6C, 0x6C},
	{0x00, 0x00, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18},
	{0x6C, 0x6C, 0x6F, 0x60, 0x6F, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C, 0x6C},
	{0x00, 0x00, 0x7F, 0x60, 0x6F, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0x6F, 0x60, 0x7F, 0x00, 0x00, 0x00},
	{0x6C, 0x6C, 0x6C, 0x6C, 0x7F, 0x00, 0x00, 0x00},
	{0x18, 0x18, 0x1F, 0x18, 0x1F, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x1F, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x18, 0x18, 0xF8, 0x00, 0x00, 0x00},
	{0x18, 0x18, 0x18, 0x18, 0xFF, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0xFF, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x18, 0x18, 0xF8, 0x18, 0x18, 0x18},
	{0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00},
	{0x18, 0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18},
	{0x6C, 0x6C, 0x6C, 0x6C, 0xEC, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0xEC, 0x0C, 0xFC, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0xFC, 0x0C, 0xEC, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0xEF, 0x00, 0xFF, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0xFF, 0x00, 0xEF, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0xEC, 0x0C, 0xEC, 0x6C, 0x6C, 0x6C},
	{0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00},
	{0x6C, 0x6C, 0xEF, 0x00, 0xEF, 0x6C, 0x6C, 0x6C},
	{0x18, 0x18, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00},
	{0x6C, 0x6C, 0x6C, 0x6C, 0xFF, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0xFF, 0x00, 0xFF, 0x18, 0x18, 0x18},
	{0x00, 0x00, 0x00, 0x00, 0xFF, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0x6C, 0x6C, 0xFC, 0x00, 0x00, 0x00},
	{0x18, 0x18, 0xF8, 0x18, 0xF8, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18},
	{0x00, 0x00, 0x00, 0x00, 0xFC, 0x6C, 0x6C, 0x6C},
	{0x6C, 0x6C, 0x6C, 0x6C, 0xFF, 0x6C, 0x6C, 0x6C},
	{0x18, 0x18, 0xFF, 0x18, 0xFF, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x18, 0x18, 0x1F, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0xF8, 0x18, 0x18, 0x18},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF},
	{0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F},
	{0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0},
	{0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x6E, 0x3B, 0x13, 0x3B, 0x6E, 0x00},
	{0x00, 0x1E, 0x33, 0x1F, 0x33, 0x1F, 0x03, 0x03},
	{0x00, 0x3F, 0x33, 0x03, 0x03, 0x03, 0x03, 0x00},
	{0x00, 0x7F, 0x36, 0x36, 0x36, 0x36, 0x36, 0x00},
	{0x3F, 0x33, 0x06, 0x0C, 0x06, 0x33, 0x3F, 0x00},
	{0x00, 0x00, 0x7E, 0x1B, 0x1B, 0x1B, 0x0E, 0x00},
	{0x00, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x03},
	{0x00, 0x6E, 0x3B, 0x18, 0x18, 0x18, 0x18, 0x00},
	{0x3F, 0x0C, 0x1E, 0x33, 0x33, 0x1E, 0x0C, 0x3F},
	{0x1C, 0x36, 0x63, 0x7F, 0x63, 0x36, 0x1C, 0x00},
	{0x1C, 0x36, 0x63, 0x63, 0x36, 0x36, 0x77, 0x00},
	{0x38, 0x0C, 0x18, 0x3E, 0x33, 0x33, 0x1E, 0x00},
	{0x00, 0x00, 0x7E, 0xDB, 0xDB, 0x7E, 0x00, 0x00},
	{0x60, 0x30, 0x7E, 0xDB, 0xDB, 0x7E, 0x06, 0x03},
	{0x1C, 0x06, 0x03, 0x1F, 0x03, 0x06, 0x1C, 0x00},
	{0x1E, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00},
	{0x00, 0x3F, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x00},
	{0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x3F, 0x00},
	{0x06, 0x0C, 0x18, 0x0C, 0x06, 0x00, 0x3F, 0x00},
	{0x18, 0x0C, 0x06, 0x0C, 0x18, 0x00, 0x3F, 0x00},
	{0x70, 0xD8, 0xD8, 0x18, 0x18, 0x18, 0x18, 0x18},
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x1B, 0x1B, 0x0E},
	{0x0C, 0x0C, 0x00, 0x3F, 0x00, 0x0C, 0x0C, 0x00},
	{0x00, 0x6E, 0x3B, 0x00, 0x6E, 0x3B, 0x00, 0x00},
	{0x1C, 0x36, 0x36, 0x1C, 0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00},
	{0xF0, 0x30, 0x30, 0x30, 0x37, 0x36, 0x3C, 0x38},
	{0x1E, 0x36, 0x36, 0x36, 0x36, 0x00, 0x00, 0x00},
	{0x0E, 0x18, 0x0C, 0x06, 0x1E, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}  // Block
	//End of borrowing
};
