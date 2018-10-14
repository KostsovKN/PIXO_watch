#include <stm32l452xx.h>
#include <stdint.h>
#include "ledmatrix.h"
#include "frames.h"
#include "spi1.h"

//uint8_t i=0;


void send_start_frame(void)
{
	send_SPI_data(0x0000);
	send_SPI_data(0x0000);
}


void send_end_frame(void)
{
	send_SPI_data(0xFFFF);
	send_SPI_data(0xFFFF);
}

//void send_LED_string(char letter)
//{
//	//char name[8]={'G','U','R','P','R','E','E','T'};
//	int8_t r=0;
//	int8_t c=0;

//	switch(letter)
//	{	
//		case 'G':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_G[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);
//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);
//								
//									}	
//							}
//					}
//				break;
//		case 'U':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_U[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);
//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);								
//									}	
//							}
//					}
//				break;

//		case 'R':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_R[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);

//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);
//								
//									}	
//							}
//					}
//				break;

//		case 'P':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_P[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);
//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);
//								
//									}	
//							}
//					}
//				break;					

//		case 'E':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_E[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);
//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);
//								
//									}	
//							}
//					}
//				break;					

//		case 'T':
//				for(r=CHAR_ROWS-1;r>=0;r--)
//					{
//						for(c=0;c<CHAR_COLMS;c++)
//							{
//								
//								if(mask_T[r][c]==1)
//									{	
//										send_SPI_data(0xFF01);
//										send_SPI_data(0x0101);
//									}
//									else
//									{
//										send_SPI_data(0xFF00);
//										send_SPI_data(0x0000);
//								
//									}	
//							}
//					}
//				break;
//	}
////	i++;
////	if(i==8)
////	{
////		i=0;
////	}
//}
			


//void draw_char_matrix_frame(char letter)
//{
//	SPI1_enable();
//	send_start_frame();
//	send_LED_string(letter);
//	send_end_frame();
//	
//}

void draw_matrix_frame(void)
{
	if(frame_sent_flag==0)
	{
		SPI1_enable();
		send_start_frame();
		int8_t r=0;
		int8_t c=0;
		for(r=0;r<ROWS;r++)
						{
							for(c=0;c<COLMS;c++)
								{
									
									if(b_w_frame[r][c]==1)
										{	
											send_SPI_data(0xFF00);
											send_SPI_data(0x000F);
										}
										else
										{
											send_SPI_data(0xFF00);
											send_SPI_data(0x0000);
									
										}	
								}
						}	
		send_end_frame();
	}

	frame_sent_flag=1;
}

void make_date_frame(void)
{
	uint32_t time= RTC->TR;
	uint8_t hr_tens=(time>>20)&(0x1);
	uint8_t hr_units=(time>>16)&(0xF);
	uint8_t min_tens=(time>>12)&(0x7);
	uint8_t min_units=(time>>8)&(0xF);
	uint8_t sec_tens=(time>>4)&(0x7);
	uint8_t sec_units=(time>>0)&(0xF);
	

	rgb_frame[0][0][0]=num_all[hr_tens][0][0]<<7;
	rgb_frame[0][1][0]=num_all[hr_tens][0][1]<<7;
	rgb_frame[0][2][0]=num_all[hr_tens][0][2]<<7;
	rgb_frame[1][0][0]=num_all[hr_tens][1][0]<<7;
	rgb_frame[1][1][0]=num_all[hr_tens][1][1]<<7;
	rgb_frame[1][2][0]=num_all[hr_tens][1][2]<<7;
	rgb_frame[2][0][0]=num_all[hr_tens][2][0]<<7;
	rgb_frame[2][1][0]=num_all[hr_tens][2][1]<<7;
	rgb_frame[2][2][0]=num_all[hr_tens][2][2]<<7;
	
	rgb_frame[0][5][0]=num_all[hr_units][0][0]<<7;
	rgb_frame[0][6][0]=num_all[hr_units][0][1]<<7;
	rgb_frame[0][7][0]=num_all[hr_units][0][2]<<7;
	rgb_frame[1][5][0]=num_all[hr_units][1][0]<<7;
	rgb_frame[1][6][0]=num_all[hr_units][1][1]<<7;
	rgb_frame[1][7][0]=num_all[hr_units][1][2]<<7;
	rgb_frame[2][5][0]=num_all[hr_units][2][0]<<7;
	rgb_frame[2][6][0]=num_all[hr_units][2][1]<<7;
	rgb_frame[2][7][0]=num_all[hr_units][2][2]<<7;
	
//	rgb_frame[0][0][0]=num_all[min_tens][0][0]<<7;
//	rgb_frame[0][1][0]=num_all[min_tens][0][1]<<7;
//	rgb_frame[0][2][0]=num_all[min_tens][0][2]<<7;
//	rgb_frame[1][0][0]=num_all[min_tens][1][0]<<7;
//	rgb_frame[1][1][0]=num_all[min_tens][1][1]<<7;
//	rgb_frame[1][2][0]=num_all[min_tens][1][2]<<7;
//	rgb_frame[2][0][0]=num_all[min_tens][2][0]<<7;
//	rgb_frame[2][1][0]=num_all[min_tens][2][1]<<7;
//	rgb_frame[2][2][0]=num_all[min_tens][2][2]<<7;
//	
//	rgb_frame[0][5][0]=num_all[min_units][0][0]<<7;
//	rgb_frame[0][6][0]=num_all[min_units][0][1]<<7;
//	rgb_frame[0][7][0]=num_all[min_units][0][2]<<7;
//	rgb_frame[1][5][0]=num_all[min_units][1][0]<<7;
//	rgb_frame[1][6][0]=num_all[min_units][1][1]<<7;
//	rgb_frame[1][7][0]=num_all[min_units][1][2]<<7;
//	rgb_frame[2][5][0]=num_all[min_units][2][0]<<7;
//	rgb_frame[2][6][0]=num_all[min_units][2][1]<<7;
//	rgb_frame[2][7][0]=num_all[min_units][2][2]<<7;

		rgb_frame[5][0][0]=num_all[min_tens][0][0]<<7;
		rgb_frame[5][1][0]=num_all[min_tens][0][1]<<7;
		rgb_frame[5][2][0]=num_all[min_tens][0][2]<<7;
		rgb_frame[6][0][0]=num_all[min_tens][1][0]<<7;
		rgb_frame[6][1][0]=num_all[min_tens][1][1]<<7;
		rgb_frame[6][2][0]=num_all[min_tens][1][2]<<7;
		rgb_frame[7][0][0]=num_all[min_tens][2][0]<<7;
		rgb_frame[7][1][0]=num_all[min_tens][2][1]<<7;
		rgb_frame[7][2][0]=num_all[min_tens][2][2]<<7;
		
		
		rgb_frame[5][5][0]=num_all[min_units][0][0]<<7;
		rgb_frame[5][6][0]=num_all[min_units][0][1]<<7;
		rgb_frame[5][7][0]=num_all[min_units][0][2]<<7;
		rgb_frame[6][5][0]=num_all[min_units][1][0]<<7;
		rgb_frame[6][6][0]=num_all[min_units][1][1]<<7;
		rgb_frame[6][7][0]=num_all[min_units][1][2]<<7;
		rgb_frame[7][5][0]=num_all[min_units][2][0]<<7;
		rgb_frame[7][6][0]=num_all[min_units][2][1]<<7;
		rgb_frame[7][7][0]=num_all[min_units][2][2]<<7;
		
//		rgb_frame[5][0][0]=num_all[sec_tens][0][0]<<7;
//		rgb_frame[5][1][0]=num_all[sec_tens][0][1]<<7;
//		rgb_frame[5][2][0]=num_all[sec_tens][0][2]<<7;
//		rgb_frame[6][0][0]=num_all[sec_tens][1][0]<<7;
//		rgb_frame[6][1][0]=num_all[sec_tens][1][1]<<7;
//		rgb_frame[6][2][0]=num_all[sec_tens][1][2]<<7;
//		rgb_frame[7][0][0]=num_all[sec_tens][2][0]<<7;
//		rgb_frame[7][1][0]=num_all[sec_tens][2][1]<<7;
//		rgb_frame[7][2][0]=num_all[sec_tens][2][2]<<7;
//		
//		
//		rgb_frame[5][5][0]=num_all[sec_units][0][0]<<7;
//		rgb_frame[5][6][0]=num_all[sec_units][0][1]<<7;
//		rgb_frame[5][7][0]=num_all[sec_units][0][2]<<7;
//		rgb_frame[6][5][0]=num_all[sec_units][1][0]<<7;
//		rgb_frame[6][6][0]=num_all[sec_units][1][1]<<7;
//		rgb_frame[6][7][0]=num_all[sec_units][1][2]<<7;
//		rgb_frame[7][5][0]=num_all[sec_units][2][0]<<7;
//		rgb_frame[7][6][0]=num_all[sec_units][2][1]<<7;
//		rgb_frame[7][7][0]=num_all[sec_units][2][2]<<7;

}

void draw_rgb_frame()
{
	
	if(frame_sent_flag==0)
	{
		//SPI1_enable();
		send_start_frame();
		int8_t r=0;
		int8_t c=0;
		for(r=0;r<ROWS;r++)
						{
							for(c=0;c<COLMS;c++)
								{
									
									if(rgb_frame[7-r][c][0]==(1<<7))
										{	
											send_SPI_data(0xE300);
											send_SPI_data(0x00012);
										}
										else
										{
											send_SPI_data(0xE100);
											send_SPI_data(0x0000);
											
											
										}	
								}
						}	
		send_end_frame();
	}

	frame_sent_flag=1;
	
}





