void isr_phone(int k){
  switch(k){
    case 0:
      isr_0_handler();
      break;
    case 1:
      isr_1_handler();
      break;
    case 2:
      isr_2_handler();
      break;
    case 3:
      isr_3_handler();
      break;
    case 4:
      isr_4_handler();
      break;
    case 5:
      isr_5_handler();
      break;
    case 6:
      isr_6_handler();
      break;
    case 7:
      isr_7_handler();
      break;
    case 8:
      isr_8_handler();
      break;
    case 9:
      isr_9_handler();
      break;
    case 10:
      isr_10_handler();
      break;
    case 11:
      isr_11_handler();
      break;
    case 12:
      isr_12_handler();
      break;
    case 13:
      isr_13_handler();
      break;
    case 14:
      isr_14_handler();
      break;
    case 15:
      isr_15_handler();
      break;
    case 16:
      isr_16_handler();
      break;
    case 17:
      isr_17_handler();
      break;
    case 18:
      isr_18_handler();
      break;
    case 19:
      isr_19_handler();
      break;
    case 20:
      isr_20_handler();
      break;
    case 21:
      isr_21_handler();
      break;
    case 22:
      isr_22_handler();
      break;
    case 23:
      isr_23_handler();
      break;
    case 24:
      isr_24_handler();
      break;
    case 25:
      isr_25_handler();
      break;
    case 26:
      isr_26_handler();
      break;
    case 27:
      isr_27_handler();
      break;
    case 28:
      isr_28_handler();
      break;
    case 29:
      isr_29_handler();
      break;
    case 30:
      isr_30_handler();
      break;
    case 31:
      isr_31_handler();
      break;
    default:
      printf("Hanlders are only 0-31.");
      break;
  }
}

void isrphone(){
	printf("    _____________       \n");
	printf("   /    AhnTri   \\     \n");
	printf("  /______ISRs_____\\    \n");
	printf("     / 1      0 \\\n");
	printf("    / 2        9 \\\n");
	printf("   ( 3    ISR   8 )\n");
	printf("    \\4  Phone  7/\n");
	printf("     \\5_______6/\n");
	printf("ISR you want to call(0-31): ");
	int k;
	k = read_int();
	isr_phone(k);
}
