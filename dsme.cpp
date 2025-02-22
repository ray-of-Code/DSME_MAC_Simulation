#include "dsme.h"

int current_time_nanoseconds()
	{
	struct timespec tm;
	clock_gettime(CLOCK_REALTIME, &tm);
	return tm.tv_nsec;
	}

int nob(int min, int max)
	{
	unsigned int dice_rolls = 2*max;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(min, max);
	return six(rng);
	}

int min_element(vector<double> vec)
	{
	int min = vec[0];

	for(int i=0; i<vec.size(); i++)
		{
		if(min > vec[i])
			{
			min = vec[i];
			}
		}
		
	return min;
	}

int Mintime(vector<double> vec)
	{
	int min = vec[0];
	int min_id = 0;

	for(int i=0; i<vec.size(); i++)
		{
		if(min > vec[i])
			{
			min = vec[i];
			min_id = i;
			}
		}
		
	return min_id;
	}

int Macmaxbe(int min, int max)
	{
	unsigned int dice_rolls = 2*max;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(min, max);
	return six(rng);
	}

int Macminbe(int min, int max)
	{
	unsigned int dice_rolls = 2*max;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(min, max);
	return six(rng);
	}

int random_be(int number)
	{
	unsigned int dice_rolls = 2*number;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(0, number);
	return six(rng);
	}

int random_pgr(int number)
	{
	unsigned int dice_rolls = 2*number;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(1, number);
	return six(rng);
	}	

int random_bs(int number)
	{
	unsigned int dice_rolls = 2*number;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(10, number);
	return six(rng);
	}	

int random_ps(int number)
	{
	unsigned int dice_rolls = 2*number;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(50, number);
	return six(rng);
	}

int random_pl(int min, int max)
	{
	unsigned int dice_rolls = 2*max;
	random::mt19937 rng(current_time_nanoseconds());
	random::uniform_int_distribution<> six(min, max);
	return six(rng);
	}	
	
double random_ber() 
	{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 0.6);
	return dis(gen);
	}	

void channel0() //channel quality eval for ch0
	{
	for(int i=0; i<(no_of_aps + no_of_sensors); i++)
		{
		for(int j=i; j<(no_of_aps + no_of_sensors); j++)
			{
			if(i==j)
				{
				ber0[i][j] = 2.0;
				}
			else
				{
				rand_b0 = random_ber();
				ber0[i][j] = rand_b0;
				ber0[j][i] = rand_b0;
				}
			}
		}
			
	ofstream berf0;

	if(first_done == 0)
		{
		berf0.open("ber0.csv");
		}
	else
		{
		berf0.open("ber0.csv", ios::app);
		}

	for(int i=0; i<(no_of_aps + no_of_sensors); i++)
		{
		for(int j=0; j<(no_of_aps + no_of_sensors); j++)
			{
			berf0<<ber0[i][j]<<"\t";	
			}
		
		berf0<<"\n";	
		}
 
	berf0.close();
	}	
	
void channel1() //channel quality eval for ch1
	{
	for(int i=0; i<(no_of_aps+no_of_sensors); i++)
		{
		for(int j=i; j<(no_of_aps+no_of_sensors); j++)
			{
			if(i==j)
				{
				ber1[i][j] = 2.0;
				}
			else
				{
				rand_b1 = random_ber();
				ber1[i][j] = rand_b1;
				ber1[j][i] = rand_b1;
				}
			}
		}
					
	ofstream berf1;

	if(first_done == 0)
		{
		berf1.open("ber1.csv");
		}
	else
		{
		berf1.open("ber1.csv", ios::app);
		}

	for(int i=0; i<(no_of_aps+no_of_sensors); i++)
		{
		for(int j=0; j<(no_of_aps+no_of_sensors); j++)
			{
			berf1<<ber1[i][j]<<"\t";	
			}
		
		berf1<<"\n";	
		}
 
	berf1.close();
	}

void channel2() //channel quality eval for ch2
	{
	for(int i=0; i<(no_of_aps+no_of_sensors); i++)
		{
		for(int j=i; j<(no_of_aps+no_of_sensors); j++)
			{
			if(i==j)
				{
				ber2[i][j] = 2.0;
				}
			else
				{
				rand_b2 = random_ber();
				ber2[i][j] = rand_b2;
				ber2[j][i] = rand_b2;
				}
			}
		}
					
	ofstream berf2;

	if(first_done == 0)
		{
		berf2.open("ber2.csv");
		}
	else
		{
		berf2.open("ber2.csv", ios::app);
		}

	for(int i=0; i<(no_of_aps+no_of_sensors); i++)
		{
		for(int j=0; j<(no_of_aps+no_of_sensors); j++)
			{
			berf2<<ber2[i][j]<<"\t";	
			}
		
		berf2<<"\n";	
		}
 
	berf2.close();
	}

void channel3() //channel quality eval for ch3
	{
	for(int i=0; i<(no_of_aps+no_of_sensors); i++)
		{
		for(int j=i; j<(no_of_aps+no_of_sensors); j++)
			{
			if(i==j)
				{
				ber3[i][j] = 2.0;
				}
			else
				{
				rand_b3 = random_ber();
				ber3[i][j] = rand_b3;
				ber3[j][i] = rand_b3;
				}
			}
		}
					
	ofstream berf3;

	if(first_done == 0)
		{
		berf3.open("ber3.csv");
		}
	else
		{
		berf3.open("ber3.csv", ios::app);
		}

	for(int i=0; i<(no_of_aps+no_of_sensors); ++i)
		{
		for(int j=0; j<(no_of_aps+no_of_sensors); ++j)
			{
			berf3<<ber3[i][j]<<"\t";	
			}
		
		berf3<<"\n";	
		}
 
	berf3.close();
	}

void csmaca0()
	{// update avg. ber calculation, transmission time(ACK), energy consumption. 		
	temp_t0 = clock();
	
	if(superframe_number % 4 == 0)
		{
		energy_consumption_aps[0] = energy_consumption_aps[0] + (32 * beacon_size * (tx - idle));

		for(int i=1; i<3; i++)
			{
			energy_consumption_aps[i]= energy_consumption_aps[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}	
		}
	
	while(clock() > temp_t0 + (32 * beacon_size)){}		

P11:	for(int i=1; i<3; i++)
		{
		if(!aps[i].empty())
			{
			macmaxbe0[i] = Macmaxbe(3, 8);
			macminbe0[i] = Macminbe(0, macmaxbe0[i]);
			be0[i] = macminbe0[i];
			nb0[i] = nob(0, 5);
			nbf0[i] = 0;
			wait0.at(i-1) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
			}
		else
			{
			check_empty0.push_back(i);  
			wait0.at(i-1) = clock() + 17 * slot_length;			
			}
		}

	if(clock() > temp_t0 + 138240 - 3500){goto cap_end_p1;}

	if(check_empty0.size() == 2)
		{				
		pit0 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
P12:	    	pit0 = pit0 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit0){}

		for(int i=1; i<3; i++)
			{
			if(!aps[i].empty())
				{
				if(check_empty0.size() > 0)
					{
					check_empty0.clear();
					}
				goto P11;
				}
			}

		if(clock() > temp_t0 + 138240 - 3500){goto cap_end_p1;}

		goto P12;
		}						
	
P13:	mintime0 = min_element(wait0);// waiting time with min value
	sensor_mintime0 = Mintime(wait0) + 1;// sensor id
	
	if(mintime0 < temp_t0 + 138240 - 3500)
		{
		while(mintime0 > clock()){}
		}
	else
		{
		goto cap_end_p1;
		}
		
	if(clock() < (temp_t0+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		t0 = (double) clock();	
			
	 	if(!aps[sensor_mintime0].empty())
			{
			lok[sensor_mintime0] = 1;

			if(request0[sensor_mintime0] != 1)
				{
				if(ber0[sensor_mintime0][0] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[0] == 0)
						{
						lok[0] = 1;
						req_packet_aps[sensor_mintime0]++;
						request0[sensor_mintime0] = 1;
							
						if(sensor_mintime0 == 1)
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] == 0 && gts_id1[i] == 0)
									{
									gts_id0[i] = sensor_mintime0;
									break;
									}
								}
							}
						else
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] == 0 && gts_id2[i] == 0)
									{
									gts_id0[i] = sensor_mintime0;
									break;
									}
								}
							}	
							
						energy_consumption_aps[0] = energy_consumption_aps[0] + (352 * (tx - idle));
						energy_consumption_aps[sensor_mintime0]= energy_consumption_aps[sensor_mintime0]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet_aps[sensor_mintime0]++;
						waste_energy[sensor_mintime0]= waste_energy[sensor_mintime0]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet_aps[sensor_mintime0]++;
					waste_energy[sensor_mintime0]= waste_energy[sensor_mintime0]+ (1920 * (tx-idle));	
					}

				data_siz[sensor_mintime0] = 64;
				energy_consumption_aps[sensor_mintime0]= energy_consumption_aps[sensor_mintime0]+ (1920 * (tx-idle)); 
				energy_consumption_aps[0] = energy_consumption_aps[0] + (1920 * (rx - idle));
				ber_sensor0[sensor_mintime0] = ber_sensor0[sensor_mintime0] + ber0[sensor_mintime0][0] * 64 * 8;
				total_bit[sensor_mintime0] = total_bit[sensor_mintime0] + (64 * 8);			
				}
			else
				{
				if(ber0[sensor_mintime0][0] <= 0.5)
					{
					if(lok[0]==0)
						{	
						lok[0] = 1;
						clatency0 = clock() - delay_aps[sensor_mintime0][0];
					
						if(aps[sensor_mintime0][0].data_type == 0 && ber0[sensor_mintime0][0] <= 0.1 && clatency0 <= aps[sensor_mintime0][0].plife0)
							{
							ap0.data_type = 0;
							check0++;
							
							if(aps[sensor_mintime0][0].data_check != 4)
								{
								ap0.data_check = 0;
								}
							else
								{
								ap0.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime0][0].data_type == 1 && ber0[sensor_mintime0][0] <= 0.3 && clatency0 <= aps[sensor_mintime0][0].plife0)
							{
							ap0.data_type = 1;
							check1++;
							
							if(aps[sensor_mintime0][0].data_check != 4)
								{
								ap0.data_check = 1;	
								}
							else
								{
								ap0.data_check = 4;
								}
							}
						else if(aps[sensor_mintime0][0].data_type == 2 && ber0[sensor_mintime0][0] <= 0.2 && clatency0 <= aps[sensor_mintime0][0].plife0)
							{
							ap0.data_type = 2;
							check2++;							

							if(aps[sensor_mintime0][0].data_check != 4)
								{
								ap0.data_check = 2;
								}
							else
								{
								ap0.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime0][0].data_type == 3 && ber0[sensor_mintime0][0] <= 0.5 && clatency0 <= aps[sensor_mintime0][0].plife0)
							{
							ap0.data_type = 3;
							check3++;
							
							if(aps[sensor_mintime0][0].data_check != 4)
								{
								ap0.data_check = 3;
								}
							else
								{
								ap0.data_check = 4;
								}	
							}
						else
							{
							ap0.data_type = aps[sensor_mintime0][0].data_type;
							ap0.data_check = 4;
							}

						if(ap0.data_type == ap0.data_check)
							{
							packet_count0[sensor_mintime0]++; 
							
							if(ap0.data_check == 0)
								{
								valid0++;
								}
							else if(ap0.data_check == 1)
								{
								valid1++;
								}
							else if(ap0.data_check == 2)
								{
								valid2++;
								}
							else			
								{
								valid3++;
								}
							}
						else
							{
							invalid[sensor_mintime0]++;
							waste_energy[sensor_mintime0]= waste_energy[sensor_mintime0]+ (31.25 * aps[sensor_mintime0][0].data_size * (tx-idle));
							}
						
						data_siz[sensor_mintime0] = aps[sensor_mintime0][0].data_size;
						latency0[sensor_mintime0]= latency0[sensor_mintime0] + (clock() - delay_aps[sensor_mintime0][0]);	
						ap0.latency = clock() - delay_aps[sensor_mintime0][0] + aps[sensor_mintime0][0].latency;
						ap0.data_size = aps[sensor_mintime0][0].data_size;
						ap0.plife0 = (aps[sensor_mintime0][0].plife0) - clatency0;

						if(ap0.plife0 < 0)
							{
							checking++;
							}

						if(ap0.data_type == 0 || ap0.data_type == 1)
							{
							cd_count++;
							c_delay0[sensor_mintime0] = c_delay0[sensor_mintime0] + (clock() - delay_aps[sensor_mintime0][0]);				
							}

						aps[sensor_mintime0].erase(aps[sensor_mintime0].begin());
						
						if(delay_aps[sensor_mintime0].size() > 0)
							{
							delay_aps[sensor_mintime0].erase(delay_aps[sensor_mintime0].begin());
							}
	
						if(aps[0].size() >= buffer_size)
							{
							packet_drop_buffer_aps[0]++;
							aps[0].erase(aps[0].begin());
							
							if(delay_aps[0].size() > 0)
								{
								delay_aps[0].erase(delay_aps[0].begin());
								}
							}

						aps[0].push_back(ap0);
						delay_aps[0].push_back(clock());
						energy_consumption_aps[0] = energy_consumption_aps[0] + (32 * 11) * (tx - idle);
						energy_consumption_aps[sensor_mintime0]= energy_consumption_aps[sensor_mintime0]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						data_siz[sensor_mintime0] = aps[sensor_mintime0][0].data_size;
						fail_packet[sensor_mintime0]++;
						aps[sensor_mintime0][0].no_ctrans++;

						if(aps[sensor_mintime0][0].no_ctrans > max_try)
							{
							packet_drop_aps[sensor_mintime0]++;
							aps[sensor_mintime0].erase(aps[sensor_mintime0].begin());
							
							if(delay_aps[sensor_mintime0].size() > 0)
								{
								delay_aps[sensor_mintime0].erase(delay_aps[sensor_mintime0].begin());
								}
							}
							
						waste_energy[sensor_mintime0]= waste_energy[sensor_mintime0]+ (31.25 * data_siz[sensor_mintime0] * (tx-idle));	
						}			
					}
				else
					{
					data_siz[sensor_mintime0] = aps[sensor_mintime0][0].data_size;
					fail_packet_aps[sensor_mintime0]++;
					aps[sensor_mintime0][0].no_ctrans++;

					if(aps[sensor_mintime0][0].no_ctrans > max_try)
						{
						packet_drop_aps[sensor_mintime0]++;
						aps[sensor_mintime0].erase(aps[sensor_mintime0].begin());
						
						if(delay_aps[sensor_mintime0].size() > 0)
							{
							delay_aps[sensor_mintime0].erase(delay_aps[sensor_mintime0].begin());
							}
						}
						
					waste_energy[sensor_mintime0]= waste_energy[sensor_mintime0]+ (31.25 * data_siz[sensor_mintime0] * (tx-idle));	
					}
						
				energy_consumption_aps[sensor_mintime0]= energy_consumption_aps[sensor_mintime0]+ (31.25 * data_siz[sensor_mintime0] * (tx-idle)); 
				energy_consumption_aps[0] = energy_consumption_aps[0] + (31.25 * data_siz[sensor_mintime0] * (rx - idle));
				ber_sensor0[sensor_mintime0] = ber_sensor0[sensor_mintime0] + ber0[sensor_mintime0][0] * data_siz[sensor_mintime0] * 8;
				total_bit[sensor_mintime0] = total_bit[sensor_mintime0] + (data_siz[sensor_mintime0] * 8);	
				}
			}
		else
			{
			wait0.at(sensor_mintime0 - 1) = clock() + 17 * slot_length;
			
			if(t0 < (temp_t0 + cap_so) - 3500)
				{	
				goto P13;
				}
			else
				{
				goto cap_end_p1;
				}
			}

		data_energy0 = data_siz[sensor_mintime0];
		
		if(!aps[sensor_mintime0].empty())
			{
			macmaxbe0[sensor_mintime0] = Macmaxbe(3, 8);
			macminbe0[sensor_mintime0] = Macminbe(0, macmaxbe0[sensor_mintime0]);
			be0[sensor_mintime0] = macminbe0[sensor_mintime0];
			nb0[sensor_mintime0] = nob(0, 5);
			nbf0[sensor_mintime0] = 0;
			wait0.at(sensor_mintime0 - 1)= clock() + random_be(pow(2, be0[sensor_mintime0]) - 1) * 320;
			}
		else
			{
			check_empty0.push_back(sensor_mintime0);  
			wait0.at(sensor_mintime0 - 1) = clock() + 17 * slot_length;
			}	

		for(int i=1; i<3; i++)
			{
			if(i!=sensor_mintime0 && (!aps[i].empty()) && wait0[i-1]<(t0 + (31.25 * data_energy0) + ack_tr))
				{
P14:				be0[i]++;

				if(be0[i]>8)
					{
					macmaxbe0[i] = Macmaxbe(3, 8);
					macminbe0[i] = Macminbe(0, macmaxbe0[i]);
					be0[i] = macminbe0[i];
					}
					
				nbf0[i]++;
							
				if(nbf0[i]>nb0[i])
					{//transmission failure
					if(!request0[i]==1)
						{
						req_fail_packet_aps[i]++;
						}
					else
						{
						packet_drop_aps[i]++;
						aps[i].erase(aps[i].begin());
						
						if(delay_aps[i].size() > 0)
							{
							delay_aps[i].erase(delay_aps[i].begin());
							}
						}
					
					if(aps[i].empty())
						{
						check_empty0.push_back(i); 
						wait0.at(i - 1) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe0[i] = Macmaxbe(3, 8);
						macminbe0[i] = Macminbe(0, macmaxbe0[i]);
						be0[i] = macminbe0[i];
						nb0[i] = nob(0, 5);
						nbf0[i] = 0;
						wait0.at(i - 1) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
		
						if(wait0[i-1]<(t0 + (31.25 * data_energy0) + ack_tr))
							{
							goto P14;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wait0.at(i - 1)= clock() + random_be(pow(2, be0[i]) - 1) * 320;

					if(wait0[i-1]<(t0 + (31.25 * data_energy0) + ack_tr))
						{
						goto P14;
						}
					}														
				}
			}

		while(clock()< (t0 + (31.25 * data_energy0) + ack_tr)){}
	
		lok[sensor_mintime0] = 0;
		lok[0] = 0;
		
		if(!check_empty0.empty())
			{
			for(int i=0; i<check_empty0.size(); i++)
				{
				if(!aps[check_empty0[i]].empty())
					{
					macmaxbe0[check_empty0[i]] = Macmaxbe(3, 8);
					macminbe0[check_empty0[i]] = Macminbe(0, macmaxbe0[check_empty0[i]]);
					be0[check_empty0[i]] = macminbe0[check_empty0[i]];
					nb0[check_empty0[i]] = nob(0, 5);
					nbf0[check_empty0[i]] = 0;
					wait0.at(check_empty0[i]-1) = clock() + random_be(pow(2, be0[check_empty0[i]]) - 1) * 320;

					if(wait0.at(check_empty0[i]-1)<(t0 + (31.25 * data_energy0) + ack_tr))
						{									
P15:						be0[check_empty0[i]]++;

						if(be0[check_empty0[i]]>8)
							{
							macmaxbe0[check_empty0[i]] = Macmaxbe(3, 8);
							macminbe0[check_empty0[i]] = Macminbe(0, macmaxbe0[check_empty0[i]]);
							be0[check_empty0[i]] = macminbe0[check_empty0[i]];
							}
							
						nbf0[check_empty0[i]]++;
							
						if(nbf0[check_empty0[i]]>nb0[check_empty0[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request0[check_empty0[i]]==1)
								{
								req_fail_packet_aps[check_empty0[i]]++;;
								}
							else
								{
								packet_drop_aps[check_empty0[i]]++;
								aps[check_empty0[i]].erase(aps[check_empty0[i]].begin());
								
								if(delay_aps[check_empty0[i]].size() > 0)
									{
							       delay_aps[check_empty0[i]].erase(delay_aps[check_empty0[i]].begin());
									}
								}

							if(aps[check_empty0[i]].empty())
								{		
								wait0.at(check_empty0[i]-1) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe0[check_empty0[i]] = Macmaxbe(3, 8);
								macminbe0[check_empty0[i]] = Macminbe(0, macmaxbe0[check_empty0[i]]);
								be0[check_empty0[i]] = macminbe0[check_empty0[i]];
								nb0[check_empty0[i]] = nob(0, 5);
								nbf0[check_empty0[i]] = 0;
								wait0.at(check_empty0[i]-1) = clock() + random_be(pow(2, be0[check_empty0[i]]) - 1) * 320;
														
								if(wait0[check_empty0[i]-1]<(t0 + (31.25 * data_energy0) + ack_tr))
									{
									goto P15;
									}
								else
									{
									it0 = check_empty0.begin();
									check_empty0.erase(it0+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wait0.at(check_empty0[i]-1)=clock()+random_be(pow(2, be0[check_empty0[i]]) - 1) * 320;

							if(wait0[check_empty0[i]-1]<(t0 + (31.25 * data_energy0) + ack_tr))
								{
								goto P15;
								}
							else
								{
								it0 = check_empty0.begin();
								check_empty0.erase(it0+i);
								}
							}
						}
					else
						{
						it0 = check_empty0.begin();
						check_empty0.erase(it0+i);
						}
					}	
				}
			}
										
		if((t0 + (31.25 * data_energy0) + ack_tr)<((temp_t0+cap_so) - 3500))
			{	
			goto P13;
			}

cap_end_p1:	while(clock()<(temp_t0+cap_so)){}
		
		if(check_empty0.size() > 0)
			{	
			check_empty0.clear();	
			}
		}

	for(int i=1; i<3; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[0] = energy_consumption_aps[0] + (cap_so * idle);
	}
	
void csmaca1()
	{// update avg. ber calculation, transmission time(ACK), energy consumption. 		
	temp_t1 = clock();
	
	if(superframe_number % 4 == 0)
		{
		energy_consumption_aps[1] = energy_consumption_aps[1] + (32 * beacon_size * (tx - idle));

		for(int i=3; i<5; i++)
			{
			energy_consumption_aps[i]= energy_consumption_aps[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}	
		}
	
	while(clock() > temp_t1 + (32 * beacon_size)){}		

P21:	for(int i=3; i<5; i++)
		{
		if(!aps[i].empty())
			{
			macmaxbe0[i] = Macmaxbe(3, 8);
			macminbe0[i] = Macminbe(0, macmaxbe0[i]);
			be0[i] = macminbe0[i];
			nb0[i] = nob(0, 5);
			nbf0[i] = 0;
			wait1.at(i-3) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
			}
		else
			{
			check_empty1.push_back(i);  
			wait1.at(i-3) = clock() + 17 * slot_length;			
			}
		}

	if(clock() > temp_t1 + 138240 - 3500){goto cap_end_p2;}

	if(check_empty1.size() == 2)
		{				
		pit1 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
P22:	    	pit1 = pit1 + 3500; // 35000= time required to generate first packet

		while(clock() <= pit1){}

		for(int i=3; i<5; i++)
			{
			if(!aps[i].empty())
				{
				if(check_empty1.size() > 0)
					{	
					check_empty1.clear();	
					}

				goto P21;
				}
			}

		if(clock() > temp_t1 + 138240 - 3500){goto cap_end_p2;}

		goto P22;
		}						

P23:	mintime1 = min_element(wait1);// waiting time with min value
	sensor_mintime1 = Mintime(wait1) + 3;// sensor id
	
	if(mintime1 < temp_t1 + 138240 - 3500)
		{
		while(mintime1 > clock()){}
		}
	else
		{
		goto cap_end_p2;
		}
		
	if(clock() < (temp_t1 + cap_so - 3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		t1 = (double) clock();	
			
	 	if(!aps[sensor_mintime1].empty())
			{
			lok[sensor_mintime1] = 1;
			
			if(request0[sensor_mintime1] != 1)
				{
				if(ber0[sensor_mintime1][1] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[1] == 0)
						{
						lok[1] = 1;
						req_packet_aps[sensor_mintime1]++;
						request0[sensor_mintime1] = 1;
							
						if(sensor_mintime1 == 3)
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] != 1 && gts_id1[i] == 0 && gts_id3[i] == no_of_sensors)
									{
									gts_id1[i] = sensor_mintime1;
									break;
									}
								}
							}
						else
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] != 1 && gts_id1[i] == 0 && gts_id4[i] == no_of_sensors)
									{
									gts_id1[i] = sensor_mintime1;
									break;
									}
								}
							}

						energy_consumption_aps[1] = energy_consumption_aps[1] + (352 * (tx - idle));
						energy_consumption_aps[sensor_mintime1]= energy_consumption_aps[sensor_mintime1]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet_aps[sensor_mintime1]++;
						waste_energy[sensor_mintime1]= waste_energy[sensor_mintime1]+ (1920 * (tx-idle));
						}
						
					}
				else
					{
					req_fail_packet_aps[sensor_mintime1]++;
					waste_energy[sensor_mintime1]= waste_energy[sensor_mintime1]+ (1920 * (tx-idle));	
					}

				data_siz[sensor_mintime1] = 64;
				energy_consumption_aps[sensor_mintime1]= energy_consumption_aps[sensor_mintime1]+ (1920 * (tx-idle)); 
				energy_consumption_aps[1] = energy_consumption_aps[1] + (1920 * (rx - idle));
				ber_sensor0[sensor_mintime1] = ber_sensor0[sensor_mintime1] + ber0[sensor_mintime1][1] * 64 * 8;
				total_bit[sensor_mintime1] = total_bit[sensor_mintime1] + (64 * 8);			
				}
			else
				{
				if(ber0[sensor_mintime1][1] <= 0.5)
					{
					if(lok[1]==0)
						{
						lok[1] = 1;
						clatency1 = clock() - delay_aps[sensor_mintime1][0];
					
						if(aps[sensor_mintime1][0].data_type == 0 && ber0[sensor_mintime1][1] <= 0.1 && clatency1 <= aps[sensor_mintime1][0].plife0)
							{
							ap1.data_type = 0;
							check00++;
							
							if(aps[sensor_mintime1][0].data_check != 4)
								{
								ap1.data_check = 0;
								}
							else
								{
								ap1.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime1][0].data_type == 1 && ber0[sensor_mintime1][1] <= 0.3 && clatency1 <= aps[sensor_mintime1][0].plife0)
							{
							ap1.data_type = 1;
							check11++;
							
							if(aps[sensor_mintime1][0].data_check != 4)
								{
								ap1.data_check = 1;
								}
							else
								{
								ap1.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime1][0].data_type == 2 && ber0[sensor_mintime1][1] <= 0.2 && clatency1 <= aps[sensor_mintime1][0].plife0)
							{
							ap1.data_type = 2;
							check22++;
							
							if(aps[sensor_mintime1][0].data_check != 4)
								{
								ap1.data_check = 2;
								}
							else
								{
								ap1.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime1][0].data_type == 3 && ber0[sensor_mintime1][1] <= 0.5 && clatency1 <= aps[sensor_mintime1][0].plife0)
							{
							ap1.data_type = 3;
							check33++;
							
							if(aps[sensor_mintime1][0].data_check != 4)
								{
								ap1.data_check = 3;
								}
							else
								{
								ap1.data_check = 4;
								}	
							}
						else
							{
							ap1.data_type = aps[sensor_mintime1][0].data_type;
							ap1.data_check = 4;
							}

						if(ap1.data_type == ap1.data_check)
							{
							packet_count0[sensor_mintime1]++; 
							
							if(ap1.data_check == 0)
								{
								valid00++;
								}
							else if(ap1.data_check == 1)
								{
								valid11++;
								}
							else if(ap1.data_check == 2)
								{
								valid22++;
								}
							else			
								{
								valid33++;
								}
							}
						else
							{
							invalid[sensor_mintime1]++;
							waste_energy[sensor_mintime1]= waste_energy[sensor_mintime1]+ (31.25 * aps[sensor_mintime1][0].data_size * (tx-idle));
							}

						data_siz[sensor_mintime1] = aps[sensor_mintime1][0].data_size;
						latency0[sensor_mintime1]= latency0[sensor_mintime1] + (clock() - delay_aps[sensor_mintime1][0]);	
						ap1.latency = clock() - delay_aps[sensor_mintime1][0] + aps[sensor_mintime1][0].latency;
						ap1.data_size = aps[sensor_mintime1][0].data_size;
						ap1.plife0 = (aps[sensor_mintime1][0].plife0) - clatency1;

						if(ap1.plife0 < 0)
							{
							checking++;
							}

						if(ap1.data_type == 0 || ap1.data_type == 1)
							{
							cd_count++;
							c_delay0[sensor_mintime1] = c_delay0[sensor_mintime1] + (clock() - delay_aps[sensor_mintime1][0]);				
							}

						aps[sensor_mintime1].erase(aps[sensor_mintime1].begin());
						
						if(delay_aps[sensor_mintime1].size() > 0)
							{
							delay_aps[sensor_mintime1].erase(delay_aps[sensor_mintime1].begin());
							}
	
						if(aps[1].size() >= buffer_size)
							{
							packet_drop_buffer_aps[1]++;
							aps[1].erase(aps[1].begin());
							
							if(delay_aps[1].size() > 0)
								{
								delay_aps[1].erase(delay_aps[1].begin());
								}
							}

						aps[1].push_back(ap1);
						delay_aps[1].push_back(clock());
						energy_consumption_aps[1] = energy_consumption_aps[1] + (32 * 11) * (tx - idle);
						energy_consumption_aps[sensor_mintime1]= energy_consumption_aps[sensor_mintime1]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						data_siz[sensor_mintime1] = aps[sensor_mintime1][0].data_size;
						fail_packet[sensor_mintime1]++;
						aps[sensor_mintime1][0].no_ctrans++;

						if(aps[sensor_mintime1][0].no_ctrans > max_try)
							{
							packet_drop_aps[sensor_mintime1]++;
							aps[sensor_mintime1].erase(aps[sensor_mintime1].begin());
							
							if(delay_aps[sensor_mintime1].size() > 0)
								{
								delay_aps[sensor_mintime1].erase(delay_aps[sensor_mintime1].begin());
								}
							}
							
						waste_energy[sensor_mintime1]= waste_energy[sensor_mintime1]+ (31.25 * data_siz[sensor_mintime1] * (tx-idle));	
						}			
					}
				else
					{
					data_siz[sensor_mintime1] = aps[sensor_mintime1][0].data_size;
					fail_packet_aps[sensor_mintime1]++;
					aps[sensor_mintime1][0].no_ctrans++;

					if(aps[sensor_mintime1][0].no_ctrans > max_try)
						{
						packet_drop_aps[sensor_mintime1]++;
						aps[sensor_mintime1].erase(aps[sensor_mintime1].begin());
						
						if(delay_aps[sensor_mintime1].size() > 0)
							{
							delay_aps[sensor_mintime1].erase(delay_aps[sensor_mintime1].begin());
							}
						}
						
					waste_energy[sensor_mintime1]= waste_energy[sensor_mintime1]+ (31.25 * data_siz[sensor_mintime1] * (tx-idle));	
					}
					
				energy_consumption_aps[sensor_mintime1]= energy_consumption_aps[sensor_mintime1]+ (31.25 * data_siz[sensor_mintime1] * (tx-idle)); 
				energy_consumption_aps[1] = energy_consumption_aps[1] + (31.25 * data_siz[sensor_mintime1] * (rx - idle));
				ber_sensor0[sensor_mintime1] = ber_sensor0[sensor_mintime1] + ber0[sensor_mintime1][1] * data_siz[sensor_mintime1] * 8;
				total_bit[sensor_mintime1] = total_bit[sensor_mintime1] + (data_siz[sensor_mintime1] * 8);	
				}
			}
		else
			{
			wait1.at(sensor_mintime1-3) = clock() + 17 * slot_length;
			
			if(t1 < (temp_t1 + cap_so) - 3500)
				{	
				goto P23;
				}
			else
				{
				goto cap_end_p2;
				}
			}

		data_energy1 = data_siz[sensor_mintime1];

		if(!aps[sensor_mintime1].empty())
			{
			macmaxbe0[sensor_mintime1] = Macmaxbe(3, 8);
			macminbe0[sensor_mintime1] = Macminbe(0, macmaxbe0[sensor_mintime1]);
			be0[sensor_mintime1] = macminbe0[sensor_mintime1];
			nb0[sensor_mintime1] = nob(0, 5);
			nbf0[sensor_mintime1] = 0;
			wait1.at(sensor_mintime1-3)= clock() + random_be(pow(2, be0[sensor_mintime1]) - 1) * 320;
			}
		else
			{
			check_empty1.push_back(sensor_mintime1);  
			wait1.at(sensor_mintime1-3) = clock() + 17 * slot_length;
			}	

		for(int i=3; i<5; i++)
			{
			if(i!=sensor_mintime1 && (!aps[i].empty()) && wait1[i-3]<(t1 + (31.25 * data_energy1) + ack_tr))
				{
P24:				be0[i]++;

				if(be0[i]>8)
					{
					macmaxbe0[i] = Macmaxbe(3, 8);
					macminbe0[i] = Macminbe(0, macmaxbe0[i]);
					be0[i] = macminbe0[i];
					}
					
				nbf0[i]++;
							
				if(nbf0[i]>nb0[i])
					{//transmission failure
					if(!request0[i]==1)
						{
						req_fail_packet_aps[i]++;
						}
					else
						{
						packet_drop_aps[i]++;
						aps[i].erase(aps[i].begin());
						
						if(delay_aps[i].size() > 0)
							{
							delay_aps[i].erase(delay_aps[i].begin());
							}
						}
					
					if(aps[i].empty())
						{
						check_empty1.push_back(i); 
						wait1.at(i-3) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe0[i] = Macmaxbe(3, 8);
						macminbe0[i] = Macminbe(0, macmaxbe0[i]);
						be0[i] = macminbe0[i];
						nb0[i] = nob(0, 5);
						nbf0[i] = 0;
						wait1.at(i-3) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
		
						if(wait1[i-3]<(t1 + (31.25 * data_energy1) + ack_tr))
							{
							goto P24;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wait1.at(i-3)= clock() + random_be(pow(2, be0[i]) - 1) * 320;

					if(wait1[i-3]<(t1 + (31.25 * data_energy1) + ack_tr))
						{
						goto P24;
						}
					}														
				}
			}

		while(clock()< (t1 + (31.25 * data_energy1) + ack_tr)){}
		
		lok[sensor_mintime1] = 0;
		lok[1] = 0;
		
		if(!check_empty1.empty())
			{
			for(int i=0; i<check_empty1.size(); i++)
				{
				if(!aps[check_empty1[i]].empty())
					{
					macmaxbe0[check_empty1[i]] = Macmaxbe(3, 8);
					macminbe0[check_empty1[i]] = Macminbe(0, macmaxbe0[check_empty1[i]]);
					be0[check_empty1[i]] = macminbe0[check_empty1[i]];
					nb0[check_empty1[i]] = nob(0, 5);
					nbf0[check_empty1[i]] = 0;
					wait1.at(check_empty1[i]-3) = clock() + random_be(pow(2, be0[check_empty1[i]]) - 1) * 320;

					if(wait1.at(check_empty1[i]-3)<(t1 + (31.25 * data_energy1) + ack_tr))
						{									
P25:						be0[check_empty1[i]]++;

						if(be0[check_empty1[i]]>8)
							{
							macmaxbe0[check_empty1[i]] = Macmaxbe(3, 8);
							macminbe0[check_empty1[i]] = Macminbe(0, macmaxbe0[check_empty1[i]]);
							be0[check_empty1[i]] = macminbe0[check_empty1[i]];
							}
							
						nbf0[check_empty1[i]]++;
							
						if(nbf0[check_empty1[i]]>nb0[check_empty1[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request0[check_empty1[i]]==1)
									{
									req_fail_packet_aps[check_empty1[i]]++;;
									}
								else
									{
									packet_drop_aps[check_empty1[i]]++;
									aps[check_empty1[i]].erase(aps[check_empty1[i]].begin());
		
									if(delay_aps[check_empty1[i]].size() > 0)
										{
								       delay_aps[check_empty1[i]].erase(delay_aps[check_empty1[i]].begin());
										}
									}

							if(aps[check_empty1[i]].empty())
								{		
								wait1.at(check_empty1[i]-3) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe0[check_empty1[i]] = Macmaxbe(3, 8);
								macminbe0[check_empty1[i]] = Macminbe(0, macmaxbe0[check_empty1[i]]);
								be0[check_empty1[i]] = macminbe0[check_empty1[i]];
								nb0[check_empty1[i]] = nob(0, 5);
								nbf0[check_empty1[i]] = 0;
								wait1.at(check_empty1[i]-3) = clock() + random_be(pow(2, be0[check_empty1[i]]) - 1) * 320;
														
								if(wait1[check_empty1[i]-3]<(t1 + (31.25 * data_energy1) + ack_tr))
									{
									goto P25;
									}
								else
									{
									it1 = check_empty1.begin();
									check_empty1.erase(it1+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wait1.at(check_empty1[i]-3)=clock()+random_be(pow(2, be0[check_empty1[i]]) - 1) * 320;

							if(wait1[check_empty1[i]-3]<(t1 + (31.25 * data_energy1) + ack_tr))
								{
								goto P25;
								}
							else
								{
								it1 = check_empty1.begin();
								check_empty1.erase(it1+i);
								}
							}
						}
					else
						{
						it1 = check_empty1.begin();
						check_empty1.erase(it1+i);
						}
					}	
				}
			}
										
		if((t1 + (31.25 * data_energy1) + ack_tr)<((temp_t1+cap_so) - 3500))
			{	
			goto P23;
			}

cap_end_p2:	while(clock()<(temp_t1+cap_so)){}
			
		if(check_empty1.size() > 0)
			{	
			check_empty1.clear();	
			}
		}

	for(int i=3; i<5; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[1] = energy_consumption_aps[1] + (cap_so * idle);
	}
	
void csmaca2()
	{// update avg. ber calculation, transmission time(ACK), energy consumption. 		
	temp_t2 = clock();
	
	if(superframe_number % 4 == 0)
		{
		energy_consumption_aps[2] = energy_consumption_aps[2] + (32 * beacon_size * (tx - idle));

		for(int i=5; i<7; i++)
			{
			energy_consumption_aps[i]= energy_consumption_aps[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}	
		}
	
	while(clock() > temp_t2 + (32 * beacon_size)){}		

P31:	for(int i=5; i<7; i++)
		{
		if(!aps[i].empty())
			{
			macmaxbe0[i] = Macmaxbe(3, 8);
			macminbe0[i] = Macminbe(0, macmaxbe0[i]);
			be0[i] = macminbe0[i];
			nb0[i] = nob(0, 5);
			nbf0[i] = 0;
			wait2.at(i-5) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
			}
		else
			{
			check_empty2.push_back(i);  
			wait2.at(i-5) = clock() + 17 * slot_length;			
			}
		}

	if(clock() > temp_t2 + 138240 - 3500){goto cap_end_p3;}

	if(check_empty2.size() == 2)
		{				
		pit2 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
P32:	    	pit2 = pit0 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit2){}

		for(int i=5; i<7; i++)
			{
			if(!aps[i].empty())
				{
				if(check_empty2.size() > 0)
					{	
					check_empty2.clear();	
					}

				goto P31;
				}
			}

		if(clock() > temp_t2 + 138240 - 3500){goto cap_end_p3;}

		goto P32;
		}						

P33:	mintime2 = min_element(wait2);// waiting time with min value
	sensor_mintime2 = Mintime(wait2) + 5;// sensor id
	
	if(mintime2 < temp_t2 + 138240 - 3500)
		{
		while(mintime2 > clock()){}
		}
	else
		{
		goto cap_end_p3;
		}
		
	if(clock() < (temp_t2+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		t2 = (double)clock();	
			
	 	if(!aps[sensor_mintime2].empty())
			{
			lok[sensor_mintime2] = 1;
			
			if(request0[sensor_mintime2] != 1)
				{
				if(ber0[sensor_mintime2][2] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[2] == 0)
						{
						lok[2] = 1;
						req_packet_aps[sensor_mintime2]++;
						request0[sensor_mintime2] = 1;
							
						if(sensor_mintime2 == 5)
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] != 2 && gts_id2[i] == 0 && gts_id5[i] == no_of_sensors)
									{
									gts_id2[i] = sensor_mintime2;
									break;
									}
								}
							}
						else
							{
							for(int i=0; i<7; i++)
								{
								if(gts_id0[i] != 2 && gts_id2[i] == 0 && gts_id6[i] == no_of_sensors)
									{
									gts_id2[i] = sensor_mintime2;
									break;
									}
								}
							}	

						energy_consumption_aps[2] = energy_consumption_aps[2] + (352 * (tx - idle));
						energy_consumption_aps[sensor_mintime2]= energy_consumption_aps[sensor_mintime2]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet_aps[sensor_mintime2]++;
						waste_energy[sensor_mintime2]= waste_energy[sensor_mintime2]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet_aps[sensor_mintime2]++;
					waste_energy[sensor_mintime2]= waste_energy[sensor_mintime2]+ (1920 * (tx-idle));	
					}

				data_siz[sensor_mintime2] = 64;
				energy_consumption_aps[sensor_mintime2]= energy_consumption_aps[sensor_mintime2]+ (1920 * (tx-idle)); 
				energy_consumption_aps[2] = energy_consumption_aps[2] + (1920 * (rx - idle));
				ber_sensor0[sensor_mintime2] = ber_sensor0[sensor_mintime2] + ber0[sensor_mintime2][2] * 64 * 8;		
				total_bit[sensor_mintime2] = total_bit[sensor_mintime2] + (64 * 8);	
				}
			else
				{
				if(ber0[sensor_mintime2][2] <= 0.5)
					{
					if(lok[2]==0)
						{
						lok[2] = 1;
						clatency2 = clock() - delay_aps[sensor_mintime2][0];
					
						if(aps[sensor_mintime2][0].data_type == 0 && ber0[sensor_mintime2][2] <= 0.1 && clatency2 <= aps[sensor_mintime2][0].plife0)
							{
							ap2.data_type = 0;
							check00++;
							
							if(aps[sensor_mintime2][0].data_check != 4)
								{
								ap2.data_check = 0;
								}
							else
								{
								ap2.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime2][0].data_type == 1 && ber0[sensor_mintime2][2] <= 0.3 && clatency2 <= aps[sensor_mintime2][0].plife0)
							{
							ap2.data_type = 1;
							check11++;
							
							if(aps[sensor_mintime2][0].data_check != 4)
								{
								ap2.data_check = 1;
								}
							else
								{
								ap2.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime2][0].data_type == 2 && ber0[sensor_mintime2][2] <= 0.2 && clatency2 <= aps[sensor_mintime2][0].plife0)
							{
							ap2.data_type = 2;
							check22++;
							
							if(aps[sensor_mintime2][0].data_check != 4)
								{
								ap2.data_check = 2;
								}
							else
								{
								ap2.data_check = 4;
								}	
							}
						else if(aps[sensor_mintime2][0].data_type == 3 && ber0[sensor_mintime2][2] <= 0.5 && clatency2 <= aps[sensor_mintime2][0].plife0)
							{
							ap2.data_type = 3;
							check33++;
							
							if(aps[sensor_mintime2][0].data_check != 4)
								{
								ap2.data_check = 3;
								}
							else
								{
								ap2.data_check = 4;
								}	
							}
						else
							{
							ap2.data_type = aps[sensor_mintime2][0].data_type;
							ap2.data_check = 4;
							}

						if(ap2.data_type == ap2.data_check)
							{
							packet_count0[sensor_mintime2]++; 
							
							if(ap2.data_check == 0)
								{
								valid00++;
								}
							else if(ap2.data_check == 1)
								{
								valid11++;
								}
							else if(ap2.data_check == 2)
								{
								valid22++;
								}
							else			
								{
								valid33++;
								}
							}
						else
							{
							invalid[sensor_mintime2]++;
							waste_energy[sensor_mintime2]= waste_energy[sensor_mintime2]+ (31.25 * aps[sensor_mintime2][0].data_size * (tx-idle));
							}

						data_siz[sensor_mintime2] = aps[sensor_mintime2][0].data_size;
						latency0[sensor_mintime2]= latency0[sensor_mintime2] + (clock() - delay_aps[sensor_mintime2][0]);	
						ap2.latency = clock() - delay_aps[sensor_mintime2][0] + aps[sensor_mintime2][0].latency;
						ap2.data_size = aps[sensor_mintime2][0].data_size;
						ap2.plife0 = (aps[sensor_mintime2][0].plife0) - clatency2;

						if(ap2.plife0 < 0)
							{
							checking++;
							}

						if(ap2.data_type == 0 || ap2.data_type == 1)
							{
							cd_count++;
							c_delay0[sensor_mintime2] = c_delay0[sensor_mintime2] + (clock() - delay_aps[sensor_mintime2][0]);				
							}

						aps[sensor_mintime2].erase(aps[sensor_mintime2].begin());
						
						if(delay_aps[sensor_mintime2].size() > 0)
							{
							delay_aps[sensor_mintime2].erase(delay_aps[sensor_mintime2].begin());
							}
	
						if(aps[2].size() >= buffer_size)
							{
							packet_drop_buffer_aps[2]++;
							aps[2].erase(aps[2].begin());
							
							if(delay_aps[2].size() > 0)
								{
								delay_aps[2].erase(delay_aps[2].begin());
								}	
							}

						aps[2].push_back(ap2);
						delay_aps[2].push_back(clock());
						energy_consumption_aps[2] = energy_consumption_aps[2] + (32 * 11) * (tx - idle);
						energy_consumption_aps[sensor_mintime2]= energy_consumption_aps[sensor_mintime2]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						data_siz[sensor_mintime2] = aps[sensor_mintime2][0].data_size;
						fail_packet_aps[sensor_mintime2]++;
						aps[sensor_mintime2][0].no_ctrans++;

						if(aps[sensor_mintime2][0].no_ctrans > max_try)
							{
							packet_drop_aps[sensor_mintime2]++;
							aps[sensor_mintime2].erase(aps[sensor_mintime2].begin());
							
							if(delay_aps[sensor_mintime2].size() > 0)
								{
								delay_aps[sensor_mintime2].erase(delay_aps[sensor_mintime2].begin());
								}
							}
							
						waste_energy[sensor_mintime2]= waste_energy[sensor_mintime2]+ (31.25 * data_siz[sensor_mintime2] * (tx-idle));	
						}			
					}
				else
					{
					data_siz[sensor_mintime2] = aps[sensor_mintime2][0].data_size;
					fail_packet_aps[sensor_mintime2]++;
					aps[sensor_mintime2][0].no_ctrans++;

					if(aps[sensor_mintime2][0].no_ctrans > max_try)
						{
						packet_drop_aps[sensor_mintime2]++;
						aps[sensor_mintime2].erase(aps[sensor_mintime2].begin());
						
						if(delay_aps[sensor_mintime2].size() > 0)
							{
							delay_aps[sensor_mintime2].erase(delay_aps[sensor_mintime2].begin());
							}
						}
						
					waste_energy[sensor_mintime2]= waste_energy[sensor_mintime2]+ (31.25 * data_siz[sensor_mintime2] * (tx-idle));	
					}
						
				energy_consumption_aps[sensor_mintime2]= energy_consumption_aps[sensor_mintime2]+ (31.25 * data_siz[sensor_mintime2] * (tx-idle)); 
				energy_consumption_aps[2] = energy_consumption_aps[2] + (31.25 * data_siz[sensor_mintime2] * (rx - idle));
				ber_sensor0[sensor_mintime2] = ber_sensor0[sensor_mintime2] + ber0[sensor_mintime2][2] * data_siz[sensor_mintime2] * 8;
				total_bit[sensor_mintime2] = total_bit[sensor_mintime2] + (data_siz[sensor_mintime2] * 8);	
				}
			}
		else
			{
			wait2.at(sensor_mintime2-5) = clock() + 17 * slot_length;
			
			if(t2 < (temp_t2 + cap_so) - 3500)
				{	
				goto P33;
				}
			else
				{
				goto cap_end_p3;
				}
			}

		data_energy2 = data_siz[sensor_mintime2];

		if(!aps[sensor_mintime2].empty())
			{
			macmaxbe0[sensor_mintime2] = Macmaxbe(3, 8);
			macminbe0[sensor_mintime2] = Macminbe(0, macmaxbe0[sensor_mintime2]);
			be0[sensor_mintime2] = macminbe0[sensor_mintime2];
			nb0[sensor_mintime2] = nob(0, 5);
			nbf0[sensor_mintime2] = 0;
			wait2.at(sensor_mintime2 - 5)= clock() + random_be(pow(2, be0[sensor_mintime2]) - 1) * 320;
			}
		else
			{
			check_empty2.push_back(sensor_mintime2);  
			wait2.at(sensor_mintime2 - 5) = clock() + 17 * slot_length;
			}	

		for(int i=5; i<7; i++)
			{
			if(i!=sensor_mintime2 && (!aps[i].empty()) && wait2[i-5]<(t2 + (31.25 * data_energy2) + ack_tr))
				{
P34:				be0[i]++;

				if(be0[i]>8)
					{
					macmaxbe0[i] = Macmaxbe(3, 8);
					macminbe0[i] = Macminbe(0, macmaxbe0[i]);
					be0[i] = macminbe0[i];
					}
					
				nbf0[i]++;
							
				if(nbf0[i]>nb0[i])
					{//transmission failure
					if(!request0[i]==1)
						{
						req_fail_packet_aps[i]++;
						}
					else
						{
						packet_drop_aps[i]++;
						aps[i].erase(aps[i].begin());
						
						if(delay_aps[i].size() > 0)
							{
							delay_aps[i].erase(delay_aps[i].begin());
							}
						}
					
					if(aps[i].empty())
						{
						check_empty2.push_back(i); 
						wait2.at(i-5) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe0[i] = Macmaxbe(3, 8);
						macminbe0[i] = Macminbe(0, macmaxbe0[i]);
						be0[i] = macminbe0[i];
						nb0[i] = nob(0, 5);
						nbf0[i] = 0;
						wait2.at(i-5) = clock() + random_be(pow(2, be0[i]) - 1) * 320;
		
						if(wait2[i-5]<(t2 + (31.25 * data_energy2) + ack_tr))
							{
							goto P34;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wait2.at(i-5)= clock() + random_be(pow(2, be0[i]) - 1) * 320;

					if(wait2[i-5]<(t2 + (31.25 * data_energy2) + ack_tr))
						{
						goto P34;
						}
					}														
				}
			}

		while(clock()< (t2 + (31.25 * data_energy2) + ack_tr)){}
		
		lok[sensor_mintime2] = 0;
		lok[2] = 0;

		if(!check_empty2.empty())
			{
			for(int i=0; i<check_empty2.size(); i++)
				{
				if(!aps[check_empty2[i]].empty())
					{
					macmaxbe0[check_empty2[i]] = Macmaxbe(3, 8);
					macminbe0[check_empty2[i]] = Macminbe(0, macmaxbe0[check_empty2[i]]);
					be0[check_empty2[i]] = macminbe0[check_empty2[i]];
					nb0[check_empty2[i]] = nob(0, 5);
					nbf0[check_empty2[i]] = 0;
					wait2.at(check_empty2[i]-5) = clock() + random_be(pow(2, be0[check_empty2[i]]) - 1) * 320;

					if(wait2.at(check_empty2[i]-5)<(t2 + (31.25 * data_energy2) + ack_tr))
						{									
P35:						be0[check_empty2[i]]++;

						if(be0[check_empty2[i]]>8)
							{
							macmaxbe0[check_empty2[i]] = Macmaxbe(3, 8);
							macminbe0[check_empty2[i]] = Macminbe(0, macmaxbe0[check_empty2[i]]);
							be0[check_empty2[i]] = macminbe0[check_empty2[i]];
							}
							
						nbf0[check_empty2[i]]++;
							
						if(nbf0[check_empty2[i]]>nb0[check_empty2[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request0[check_empty2[i]]==1)
								{
								req_fail_packet_aps[check_empty2[i]]++;;
								}
							else
								{
								packet_drop_aps[check_empty2[i]]++;
								aps[check_empty2[i]].erase(aps[check_empty2[i]].begin());
								
								if(delay_aps[check_empty2[i]].size() > 0)
									{
							        delay_aps[check_empty2[i]].erase(delay_aps[check_empty2[i]].begin());
									}
								}

							if(aps[check_empty2[i]].empty())
								{		
								wait2.at(check_empty2[i]-5) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe0[check_empty2[i]] = Macmaxbe(3, 8);
								macminbe0[check_empty2[i]] = Macminbe(0, macmaxbe0[check_empty2[i]]);
								be0[check_empty2[i]] = macminbe0[check_empty2[i]];
								nb0[check_empty2[i]] = nob(0, 5);
								nbf0[check_empty2[i]] = 0;
								wait2.at(check_empty2[i]-5) = clock() + random_be(pow(2, be0[check_empty2[i]]) - 1) * 320;
														
								if(wait2[check_empty2[i]-5]<(t2 + (31.25 * data_energy2) + ack_tr))
									{
									goto P35;
									}
								else
									{
									it2 = check_empty2.begin();
									check_empty2.erase(it2+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wait2.at(check_empty2[i]-5)=clock()+random_be(pow(2, be0[check_empty2[i]]) - 1) * 320;

							if(wait2[check_empty2[i]-5]<(t2 + (31.25 * data_energy2) + ack_tr))
								{
								goto P35;
								}
							else
								{
								it2 = check_empty2.begin();
								check_empty2.erase(it2+i);
								}
							}
						}
					else
						{
						it2 = check_empty2.begin();
						check_empty2.erase(it2+i);
						}
					}	
				}
			}
										
		if((t2 + (31.25 * data_energy2) + ack_tr)<((temp_t2+cap_so) - 3500))
			{	
			goto P33;
			}

cap_end_p3:	while(clock()<(temp_t2+cap_so)){}
			
		if(check_empty2.size() > 0)
			{	
			check_empty2.clear();	
			}
		}

	for(int i=5; i<7; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[2] = energy_consumption_aps[2] + (cap_so * idle);
	}
	
void csmaca3()
	{
	temp_c0 = clock();
	
	if(superframe_number % 4 == 1)
		{
		energy_consumption_aps[3] = energy_consumption_aps[3] + (32 * beacon_size * (tx - idle));

		for(int i=0; i<(no_of_sensors/4); i++)
			{
			energy_consumption[i]= energy_consumption[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}
		}

	while(clock() < temp_c0 + (32 * beacon_size)){}
	
C11:	for(int i=0; i<(no_of_sensors/4); i++)
		{
		if(!nodes[i].empty())
			{
			macmaxbe1[i] = Macmaxbe(3, 8);
			macminbe1[i] = Macminbe(0, macmaxbe1[i]);
			be1[i] = macminbe1[i];
			nb1[i] = nob(0, 5);
			nbf1[i] = 0;
			wait3.at(i) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
			}
		else
			{
			check_empty3.push_back(i);  
			wait3.at(i) = clock() + 17 * slot_length;			
			}
		}
	
	if(clock() > temp_c0 + cap_so - 3500){goto cap_end_c1;}

	if(check_empty3.size() == (no_of_sensors/4))
		{
		pit3 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
C12:		pit3 = pit3 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit3){}

		for(int i=0; i<(no_of_sensors/4); i++)
			{
			if(!nodes[i].empty())
				{
				if(check_empty3.size() > 0)
					{	
					check_empty3.clear();	
					}

				goto C11;
				}
			}

		if(clock() > temp_c0 + cap_so - 3500){goto cap_end_c1;}		
	
		goto C12;
		}	
	
	for(int i=0; i<(no_of_sensors/4); i++)
		{
		wt1.at(i) = wait3[i]; 
		}

C13:	mintime3 = min_element(wt1);// waiting time with min value
	sensor_mintime3 = Mintime(wt1);// sensor id
	
	if(mintime3 < temp_c0 + cap_so - 3500)
		{
		while(mintime3 > clock()){}
		}
	else
		{
		goto cap_end_c1;
		}
		
	if(clock() < (temp_c0+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		ct0 = (double) clock();	
			
	 	if(!nodes[sensor_mintime3].empty())
			{
			if(request1[sensor_mintime3] != 1)
				{
				if(ber0[no_of_aps + sensor_mintime3][3] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[3] == 0 && lok[1] == 0)
						{
						lok[3] = 1;
						req_packet[sensor_mintime3]++;			
						request1[sensor_mintime3] = 1;
							
						for(int i=0; i<7; i++)
							{
							if(gts_id1[i] != 3 && gts_id0[i] != 1 && gts_id3[i] == no_of_sensors)
								{
								gts_id3[i] = sensor_mintime3;
								break;
								}
							}
						
						energy_consumption_aps[3] = energy_consumption_aps[3] + (352 * (tx - idle));
						energy_consumption[sensor_mintime3]= energy_consumption[sensor_mintime3]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet[sensor_mintime3]++;
						waste_energy[sensor_mintime3]= waste_energy[sensor_mintime3]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet[sensor_mintime3]++;
					waste_energy[sensor_mintime3]= waste_energy[sensor_mintime3]+ (1920 * (tx-idle));	
					}

				energy_consumption[sensor_mintime3]= energy_consumption[sensor_mintime3]+ (1920 * (tx-idle)); 
				energy_consumption_aps[3] = energy_consumption_aps[3] + (1920 * (rx - idle));
				ber_sensor1[sensor_mintime3] = ber_sensor1[sensor_mintime3] + ber0[no_of_aps + sensor_mintime3][3] * 64 * 8;			
				total_bit[sensor_mintime3] = total_bit[sensor_mintime3] + (64 * 8);
				}
			else
				{
				if(ber0[no_of_aps + sensor_mintime3][0] <= 0.5)
					{
					if(lok[3] == 0 && lok[1] == 0)
						{
						lok[3] = 1;
						clatency3 = clock() - delay_time[sensor_mintime3][0];
					
						if(0 <= sensor_mintime3 && sensor_mintime3 <(no_of_sensors/16) && ber0[no_of_aps + sensor_mintime3][3] <= 0.1 && clatency3 <= pl1[sensor_mintime3])
							{
							ap3.data_type = 0;
							ap3.data_check = 0;
							check000++;	
							}
						else if((no_of_sensors/16)<= sensor_mintime3 && sensor_mintime3 <(no_of_sensors/8) && ber0[no_of_aps + sensor_mintime3][3] <= 0.3 && clatency3 <= pl1[sensor_mintime3])
							{
							ap3.data_type = 1;
							ap3.data_check = 1;	
							check111++;
							}
						else if((no_of_sensors/8)<= sensor_mintime3 && sensor_mintime3 <(3*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime3][3] <= 0.2 && clatency3 <= pl1[sensor_mintime3])
							{
							ap3.data_type = 2;
							ap3.data_check = 2;
							check222++;
							}
						else if((3*(no_of_sensors/16))<= sensor_mintime3 && sensor_mintime3 <(no_of_sensors/4) && ber0[no_of_aps + sensor_mintime3][3] <= 0.5 && clatency3 <= pl1[sensor_mintime3])
							{
							ap3.data_type = 3;
							ap3.data_check = 3;
							check333++;	
							}
						else
							{
							if(0 <= sensor_mintime3 && sensor_mintime3 <(no_of_sensors/16))
								{
								ap3.data_type = 0;
								}
							else if((no_of_sensors/16)<= sensor_mintime3 && sensor_mintime3 <(no_of_sensors/8))
								{
								ap3.data_type = 1;
								}
							else if((no_of_sensors/8)<= sensor_mintime3 && sensor_mintime3 <(3*(no_of_sensors/16)))
								{
								ap3.data_type = 2;
								}
							else
								{
								ap3.data_type = 3;
								}			
							
							ap3.data_check = 4;
							}
	
						if(ap3.data_type == ap3.data_check)
							{
							packet_count1[sensor_mintime3]++;
							
							if(ap3.data_check == 0)
								{
								valid000++;
								}
							else if(ap3.data_check == 1)
								{
								valid111++;
								}
							else if(ap3.data_check == 2)
								{
								valid222++;
								}
							else			
								{
								valid333++;
								}
 							}
						else
							{
							invalid[sensor_mintime3+7]++;
							waste_energy[sensor_mintime3]= waste_energy[sensor_mintime3]+ (tr[sensor_mintime3] * (tx-idle));
							}
	
						latency1[sensor_mintime3]= latency1[sensor_mintime3] + (clock() - delay_time[sensor_mintime3][0]);	
						ap3.latency = clock() - delay_time[sensor_mintime3][0];
						ap3.data_size = ps[sensor_mintime3];
						ap3.plife0 = nodes[sensor_mintime3][0].plife1 - clatency3;

						if(ap3.plife0 < 0)
							{
							checking++;
							}

						if(ap3.data_type == 0 || ap3.data_type == 1)
							{
							cd_count++;
							c_delay1[sensor_mintime3] = c_delay1[sensor_mintime3] + (clock() - delay_time[sensor_mintime3][0]);				
							}

						nodes[sensor_mintime3].erase(nodes[sensor_mintime3].begin());
						
						if(delay_time[sensor_mintime3].size() > 0)
							{
							delay_time[sensor_mintime3].erase(delay_time[sensor_mintime3].begin());
							}
	
						if(aps[3].size() >= buffer_size)
							{
							packet_drop_buffer_aps[3]++;
							aps[3].erase(aps[3].begin());
							
							if(delay_aps[3].size() > 0)
								{
								delay_aps[3].erase(delay_aps[3].begin());
								}
							}

						aps[3].push_back(ap3);
						delay_aps[3].push_back(clock());
						energy_consumption_aps[3] = energy_consumption_aps[3] + (32 * 11) * (tx - idle);
						energy_consumption[sensor_mintime3]= energy_consumption[sensor_mintime3]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						fail_packet[sensor_mintime3]++;
						nodes[sensor_mintime3][0].no_strans++;

						if(nodes[sensor_mintime3][0].no_strans > max_try)
							{
							packet_drop[sensor_mintime3]++;
							nodes[sensor_mintime3].erase(nodes[sensor_mintime3].begin());
							
							if(delay_time[sensor_mintime3].size() > 0)
								{
								delay_time[sensor_mintime3].erase(delay_time[sensor_mintime3].begin());
								}
							}
							
						waste_energy[sensor_mintime3]= waste_energy[sensor_mintime3]+ (tr[sensor_mintime3] * (tx-idle));	
						}	
					}
				else
					{
					fail_packet[sensor_mintime3]++;
					nodes[sensor_mintime3][0].no_strans++;

					if(nodes[sensor_mintime3][0].no_strans > max_try)
						{
						packet_drop[sensor_mintime3]++;
						nodes[sensor_mintime3].erase(nodes[sensor_mintime3].begin());
						
						if(delay_time[sensor_mintime3].size() > 0)
							{
							delay_time[sensor_mintime3].erase(delay_time[sensor_mintime3].begin());
							}
						}
					
					waste_energy[sensor_mintime3]= waste_energy[sensor_mintime3]+ (tr[sensor_mintime3] * (tx-idle));	
					}
					
				energy_consumption[sensor_mintime3]= energy_consumption[sensor_mintime3]+ (tr[sensor_mintime3] * (tx-idle)); 
				energy_consumption_aps[3] = energy_consumption_aps[3] + (tr[sensor_mintime3] * (rx - idle));
				ber_sensor1[sensor_mintime3] = ber_sensor1[sensor_mintime3] + ber0[no_of_aps + sensor_mintime3][3] * ps[sensor_mintime3] * 8;
				total_bit[sensor_mintime3] = total_bit[sensor_mintime3] + (ps[sensor_mintime3] * 8);	
				}
			}
		else
			{
			wt1.at(sensor_mintime3) = clock() + 17 * slot_length;
			
			if(ct0 < (temp_c0 + cap_so) - (tr[sensor_mintime3] + ack_tr))
				{	
				goto C13;
				}
			else
				{
				goto cap_end_c1;
				}
			}

		if(!nodes[sensor_mintime3].empty())
			{
			macmaxbe1[sensor_mintime3] = Macmaxbe(3, 8);
			macminbe1[sensor_mintime3] = Macminbe(0, macmaxbe1[sensor_mintime3]);
			be1[sensor_mintime3] = macminbe1[sensor_mintime3];
			nb1[sensor_mintime3] = nob(0, 5);
			nbf1[sensor_mintime3] = 0;
			wt1.at(sensor_mintime3)= clock() + random_be(pow(2, be1[sensor_mintime3]) - 1) * 320;
			}
		else
			{
			check_empty3.push_back(sensor_mintime3);  
			wt1.at(sensor_mintime3) = clock() + 17 * slot_length;
			}	

		for(int i=0; i<no_of_sensors/4; i++)
			{
			if(i!=sensor_mintime3 && (!nodes[i].empty()) && wt1[i]<(ct0 + tr[sensor_mintime3] + ack_tr))
				{
C14:				be1[i]++;

				if(be1[i]>8)
					{
					macmaxbe1[i] = Macmaxbe(3, 8);
					macminbe1[i] = Macminbe(0, macmaxbe1[i]);
					be1[i] = macminbe1[i];
					}
					
				nbf1[i]++;
							
				if(nbf1[i]>nb1[i])
					{//transmission failure
					if(!request1[i]==1)
						{
						req_fail_packet[i]++;
						}
					else
						{
						packet_drop[i]++;
						nodes[i].erase(nodes[i].begin());
						
						if(delay_time[i].size() > 0)
							{
							delay_time[i].erase(delay_time[i].begin());
							}
						}
					
					if(nodes[i].empty())
						{
						check_empty3.push_back(i); 
						wt1.at(i) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe1[i] = Macmaxbe(3, 8);
						macminbe1[i] = Macminbe(0, macmaxbe1[i]);
						be1[i] = macminbe1[i];
						nb1[i] = nob(0, 5);
						nbf1[i] = 0;
						wt1.at(i) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
		
						if(wt1[i]<(ct0 + tr[sensor_mintime3] + ack_tr))
							{
							goto C14;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wt1.at(i)= clock() + random_be(pow(2, be1[i]) - 1) * 320;

					if(wt1[i]<(ct0 + tr[sensor_mintime3] + ack_tr))
						{
						goto C14;
						}
					}														
				}
			}

		while(clock()<ct0+ tr[sensor_mintime3] + ack_tr){}
		
		lok[3] = 0;

		if(!check_empty3.empty())
			{
			for(int i=0; i<check_empty3.size(); i++)
				{
				if(!nodes[check_empty3[i]].empty())
					{
					macmaxbe1[check_empty3[i]] = Macmaxbe(3, 8);
					macminbe1[check_empty3[i]] = Macminbe(0, macmaxbe1[check_empty3[i]]);
					be1[check_empty3[i]] = macminbe1[check_empty3[i]];
					nb1[check_empty3[i]] = nob(0, 5);
					nbf1[check_empty3[i]] = 0;
					wt1.at(check_empty3[i]) = clock() + random_be(pow(2, be1[check_empty3[i]]) - 1) * 320;

					if(wt1.at(check_empty3[i])<(clock()<ct0+ tr[sensor_mintime3] + ack_tr))
						{									
C15:						be1[check_empty3[i]]++;

						if(be1[check_empty3[i]]>8)
							{
							macmaxbe1[check_empty3[i]] = Macmaxbe(3, 8);
							macminbe1[check_empty3[i]] = Macminbe(0, macmaxbe1[check_empty3[i]]);
							be1[check_empty3[i]] = macminbe1[check_empty3[i]];
							}
							
						nbf1[check_empty3[i]]++;
							
						if(nbf1[check_empty3[i]]>nb1[check_empty3[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request1[check_empty3[i]]==1)
								{
								req_fail_packet[check_empty3[i]]++;;
								}
							else
								{
								packet_drop[check_empty3[i]]++;
								nodes[check_empty3[i]].erase(nodes[check_empty3[i]].begin());
							   
							   	if(delay_time[check_empty3[i]].size() > 0)
							   		{
							      	delay_time[check_empty3[i]].erase(delay_time[check_empty3[i]].begin());
									}
								}

							if(nodes[check_empty3[i]].empty())
								{		
								wt1.at(check_empty3[i]) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe1[check_empty3[i]] = Macmaxbe(3, 8);
								macminbe1[check_empty3[i]] = Macminbe(0, macmaxbe1[check_empty3[i]]);
								be1[check_empty3[i]] = macminbe1[check_empty3[i]];
								nb1[check_empty3[i]] = nob(0, 5);
								nbf1[check_empty3[i]] = 0;
								wt1.at(check_empty3[i]) = clock() + random_be(pow(2, be1[check_empty3[i]]) - 1) * 320;
														
								if(wt1[check_empty3[i]]<(ct0 + tr[sensor_mintime3] + ack_tr))
									{
									goto C15;
									}
								else
									{
									it3 = check_empty3.begin();
									check_empty3.erase(it3+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wt1.at(check_empty3[i])=clock()+random_be(pow(2, be1[check_empty3[i]]) - 1) * 320;

							if(wt1[check_empty3[i]]<(ct0 + tr[sensor_mintime3] + ack_tr))
								{
								goto C15;
								}
							else
								{
								it3 = check_empty3.begin();
								check_empty3.erase(it3+i);
								}
							}
						}
					else
						{
						it3 = check_empty3.begin();
						check_empty3.erase(it3+i);
						}
					}	
				}
			}
										
		if((ct0 + tr[sensor_mintime3] + ack_tr)<((temp_c0+cap_so) - 3500))
			{	
			goto C13;
			}

cap_end_c1:	while(clock()<(temp_c0+cap_so)){}
			
		if(check_empty3.size() > 0)
			{	
			check_empty3.clear();	
			}
		}			
		
	for(int i=0; i<(no_of_sensors/4); i++)
		{
		energy_consumption[i] = energy_consumption[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[3] = energy_consumption_aps[3] + (cap_so * idle);
	}
	
void csmaca4()
	{
	temp_c1 = clock();
	
	if(superframe_number % 4 == 1)
		{
		energy_consumption_aps[4] = energy_consumption_aps[4] + (32 * beacon_size * (tx - idle));

		for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
			{
			energy_consumption[i]= energy_consumption[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}
		}

	while(clock() < temp_c1 + (32 * beacon_size)){}
	
C21:	for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
		{
		if(!nodes[i].empty())
			{
			macmaxbe1[i] = Macmaxbe(3, 8);
			macminbe1[i] = Macminbe(0, macmaxbe1[i]);
			be1[i] = macminbe1[i];
			nb1[i] = nob(0, 5);
			nbf1[i] = 0;
			wait4.at(i-(no_of_sensors/4)) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
			}
		else
			{
			check_empty4.push_back(i);  
			wait4.at(i-(no_of_sensors/4)) = clock() + 17 * slot_length;			
			}
		}
		
	if(clock() > temp_c1 + cap_so - 3500){goto cap_end_c2;}

	if(check_empty4.size() == (no_of_sensors/4))
		{
		pit4 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
C22:		pit4 = pit4 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit4){}

		for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
			{
			if(!nodes[i].empty())
				{
				if(check_empty4.size() > 0)
					{	
					check_empty4.clear();	
					}

				goto C21;
				}
			}

		if(clock() > temp_c1 + cap_so - 3500){goto cap_end_c2;}		
	
		goto C22;
		}	
	
	for(int i=0; i<(no_of_sensors/4); i++)
		{
		wt2.at(i) = wait4[i]; 
		}
	
C23:	mintime4 = min_element(wt2);// waiting time with min value
	sensor_mintime4 = Mintime(wt2) + (no_of_sensors/4);// sensor id
	
	if(mintime4 < temp_c1 + cap_so - 3500)
		{
		while(mintime4 > clock()){}
		}
	else
		{
		goto cap_end_c2;
		}
		
	if(clock() < (temp_c1+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		ct1 = (double) clock();	
			
	 	if(!nodes[sensor_mintime4].empty())
			{
			if(request1[sensor_mintime4] != 1)
				{
				if(ber0[no_of_aps + sensor_mintime4][4] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[4] == 0 && lok[1] == 0)
						{
						lok[4] = 1;
						req_packet[sensor_mintime4]++;			
						request1[sensor_mintime4] = 1;
							
						for(int i=0; i<7; i++)
							{
							if(gts_id1[i] != 4 && gts_id0[i] != 1 && gts_id4[i] == no_of_sensors)
								{
								gts_id4[i] = sensor_mintime4;
								break;
								}
							}
						
						energy_consumption_aps[4] = energy_consumption_aps[4] + (352 * (tx - idle));
						energy_consumption[sensor_mintime4]= energy_consumption[sensor_mintime4]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet[sensor_mintime4]++;
						waste_energy[sensor_mintime4]= waste_energy[sensor_mintime4]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet[sensor_mintime4]++;	
					waste_energy[sensor_mintime4]= waste_energy[sensor_mintime4]+ (1920 * (tx-idle));
					}

				energy_consumption[sensor_mintime4]= energy_consumption[sensor_mintime4]+ (1920 * (tx-idle)); 
				energy_consumption_aps[4] = energy_consumption_aps[4] + (1920 * (rx - idle));
				ber_sensor1[sensor_mintime4] = ber_sensor1[sensor_mintime4] + ber0[no_of_aps + sensor_mintime4][4] * 64 * 8;		
				total_bit[sensor_mintime4] = total_bit[sensor_mintime4] + (64 * 8);	
				}
			else
				{
				if(ber0[no_of_aps + sensor_mintime4][4] <= 0.5)
					{
					if(lok[4] == 0 && lok[1] == 0)
						{
						lok[4] = 1;
						clatency4 = clock() - delay_time[sensor_mintime4][0];
					
						if((no_of_sensors/4)<= sensor_mintime4 && sensor_mintime4 <(5*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime4][4] <= 0.1 && clatency4 <= pl1[sensor_mintime4])
							{
							ap4.data_type = 0;
							ap4.data_check = 0;
							check000++;
							}
						else if((5*(no_of_sensors/16))<= sensor_mintime4 && sensor_mintime4 <(3*(no_of_sensors/8)) && ber0[no_of_aps + sensor_mintime4][4] <= 0.3 && clatency4 <= pl1[sensor_mintime4])
							{
							ap4.data_type = 1;
							ap4.data_check = 1;
							check111++;
							}
						else if((3*(no_of_sensors/8))<= sensor_mintime4 && sensor_mintime4 <(7*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime4][4] <= 0.2 && clatency4 <= pl1[sensor_mintime4])
							{
							ap4.data_type = 2;
							ap4.data_check = 2;	
							check222++;
							}
						else if((7*(no_of_sensors/16))<= sensor_mintime4 && sensor_mintime4 <(no_of_sensors/2) && ber0[no_of_aps + sensor_mintime4][4] <= 0.5 && clatency4 <= pl1[sensor_mintime4])
							{
							ap4.data_type = 3;
							ap4.data_check = 3;	
							check333++;
							}
						else
							{
							if((no_of_sensors/4)<= sensor_mintime4 && sensor_mintime4 <(5*(no_of_sensors/16)))
								{
								ap4.data_type = 0;
								}
							else if((5*(no_of_sensors/16))<= sensor_mintime4 && sensor_mintime4 <(3*(no_of_sensors/8)))
								{
								ap4.data_type = 1;
								}
							else if((3*(no_of_sensors/8))<= sensor_mintime4 && sensor_mintime4 <(7*(no_of_sensors/16)))
								{
								ap4.data_type = 2;
								}
							else
								{
								ap4.data_type = 3;
								}
							
							ap4.data_check = 4;
							}
	
						if(ap4.data_type == ap4.data_check)
							{
							packet_count1[sensor_mintime4]++;
							
							if(ap4.data_check == 0)
								{
								valid000++;
								}
							else if(ap4.data_check == 1)
								{
								valid111++;
								}
							else if(ap4.data_check == 2)
								{
								valid222++;
								}
							else			
								{
								valid333++;
								}
 							}
						else
							{
							invalid[sensor_mintime4+7]++;
							waste_energy[sensor_mintime4] = waste_energy[sensor_mintime4]+ (tr[sensor_mintime4] * (tx-idle));
							}
	
						latency1[sensor_mintime4]= latency1[sensor_mintime4] + (clock() - delay_time[sensor_mintime4][0]);	
						ap4.latency = clock() - delay_time[sensor_mintime4][0];
						ap4.data_size = ps[sensor_mintime4];
						ap4.plife0 = nodes[sensor_mintime4][0].plife1 - clatency4;

						if(ap4.plife0 < 0)
							{
							checking++;
							}

						if(ap4.data_type == 0 || ap4.data_type == 1)
							{
							cd_count++;
							c_delay1[sensor_mintime4] = c_delay1[sensor_mintime4] + (clock() - delay_time[sensor_mintime4][0]);				
							}

						nodes[sensor_mintime4].erase(nodes[sensor_mintime4].begin());
						
						if(delay_time[sensor_mintime4].size() > 0)
							{
							delay_time[sensor_mintime4].erase(delay_time[sensor_mintime4].begin());
							}
	
						if(aps[4].size() >= buffer_size)
							{
							packet_drop_buffer_aps[4]++;
							aps[4].erase(aps[4].begin());
							
							if(delay_aps[4].size() > 0)
								{
								delay_aps[4].erase(delay_aps[4].begin());
								}
							}

						aps[4].push_back(ap4);
						delay_aps[4].push_back(clock());
						energy_consumption_aps[4] = energy_consumption_aps[4] + (32 * 11) * (tx - idle);
						energy_consumption[sensor_mintime4]= energy_consumption[sensor_mintime4]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						fail_packet[sensor_mintime4]++;
						nodes[sensor_mintime4][0].no_strans++;

						if(nodes[sensor_mintime4][0].no_strans > max_try)
							{
							packet_drop[sensor_mintime4]++;
							nodes[sensor_mintime4].erase(nodes[sensor_mintime4].begin());
							
							if(delay_time[sensor_mintime4].size() > 0)
								{
								delay_time[sensor_mintime4].erase(delay_time[sensor_mintime4].begin());
								}
							}
							
						waste_energy[sensor_mintime4] = waste_energy[sensor_mintime4]+ (tr[sensor_mintime4] * (tx-idle));	
						}	
					}
				else
					{
					fail_packet[sensor_mintime4]++;
					nodes[sensor_mintime4][0].no_strans++;

					if(nodes[sensor_mintime4][0].no_strans > max_try)
						{
						packet_drop[sensor_mintime4]++;
						nodes[sensor_mintime4].erase(nodes[sensor_mintime4].begin());
						
						if(delay_time[sensor_mintime4].size() > 0)
							{
							delay_time[sensor_mintime4].erase(delay_time[sensor_mintime4].begin());
							}			
						}
						
					waste_energy[sensor_mintime4] = waste_energy[sensor_mintime4]+ (tr[sensor_mintime4] * (tx-idle));	
					}
					
				energy_consumption[sensor_mintime4]= energy_consumption[sensor_mintime4]+ (tr[sensor_mintime4] * (tx-idle)); 
				energy_consumption_aps[4] = energy_consumption_aps[4] + (tr[sensor_mintime4] * (rx - idle));
				ber_sensor1[sensor_mintime4] = ber_sensor1[sensor_mintime4] + ber0[no_of_aps + sensor_mintime4][4] * ps[sensor_mintime4] * 8;	
				total_bit[sensor_mintime4] = total_bit[sensor_mintime4] + (ps[sensor_mintime4] * 8);
				}
			}
		else
			{
			wt2.at(sensor_mintime4 - (no_of_sensors/4)) = clock() + 17 * slot_length;
			
			if(ct1 < (temp_c1 + cap_so) - (tr[sensor_mintime4] + ack_tr))
				{	
				goto C23;
				}
			else
				{
				goto cap_end_c2;
				}
			}	
		
		if(!nodes[sensor_mintime4].empty())
			{
			macmaxbe1[sensor_mintime4] = Macmaxbe(3, 8);
			macminbe1[sensor_mintime4] = Macminbe(0, macmaxbe1[sensor_mintime4]);
			be1[sensor_mintime4] = macminbe1[sensor_mintime4];
			nb1[sensor_mintime4] = nob(0, 5);
			nbf1[sensor_mintime4] = 0;
			wt2.at(sensor_mintime4 - (no_of_sensors/4))= clock() + random_be(pow(2, be1[sensor_mintime4]) - 1) * 320;
			}
		else
			{
			check_empty4.push_back(sensor_mintime4);  
			wt2.at(sensor_mintime4 - (no_of_sensors/4)) = clock() + 17 * slot_length;
			}	

		for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
			{
			if(i!=sensor_mintime4 && (!nodes[i].empty()) && wt2[i - (no_of_sensors/4)]<(ct1 + tr[sensor_mintime4] + ack_tr))
				{
C24:				be1[i]++;

				if(be1[i]>8)
					{
					macmaxbe1[i] = Macmaxbe(3, 8);
					macminbe1[i] = Macminbe(0, macmaxbe1[i]);
					be1[i] = macminbe1[i];
					}
					
				nbf1[i]++;
							
				if(nbf1[i]>nb1[i])
					{//transmission failure
					if(!request1[i]==1)
						{
						req_fail_packet[i]++;
						}
					else
						{
						packet_drop[i]++;
						nodes[i].erase(nodes[i].begin());
						
						if(delay_time[i].size() > 0)
							{
							delay_time[i].erase(delay_time[i].begin());
							}	
						}
					
					if(nodes[i].empty())
						{
						check_empty4.push_back(i); 
						wt2.at(i - (no_of_sensors/4)) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe1[i] = Macmaxbe(3, 8);
						macminbe1[i] = Macminbe(0, macmaxbe1[i]);
						be1[i] = macminbe1[i];
						nb1[i] = nob(0, 5);
						nbf1[i] = 0;
						wt2.at(i - (no_of_sensors/4)) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
		
						if(wt2[i - (no_of_sensors/4)]<(ct1 + tr[sensor_mintime4] + ack_tr))
							{
							goto C24;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wt2.at(i - (no_of_sensors/4))= clock() + random_be(pow(2, be1[i]) - 1) * 320;

					if(wt2[i - (no_of_sensors/4)]<(ct1 + tr[sensor_mintime4] + ack_tr))
						{
						goto C24;
						}
					}												
				}
			}

		while(clock()<ct1+ tr[sensor_mintime4] + ack_tr){}
		
		lok[4] = 0;

		if(!check_empty4.empty())
			{
			for(int i=0; i<check_empty4.size(); i++)
				{
				if(!nodes[check_empty4[i]].empty())
					{
					macmaxbe1[check_empty4[i]] = Macmaxbe(3, 8);
					macminbe1[check_empty4[i]] = Macminbe(0, macmaxbe1[check_empty4[i]]);
					be1[check_empty4[i]] = macminbe1[check_empty4[i]];
					nb1[check_empty4[i]] = nob(0, 5);
					nbf1[check_empty4[i]] = 0;

					wt2.at(check_empty4[i] - (no_of_sensors/4)) = clock() + random_be(pow(2, be1[check_empty4[i]]) - 1) * 320;

					if(wt2.at(check_empty4[i] - (no_of_sensors/4))<(ct1 + tr[sensor_mintime4] + ack_tr))
						{									
C25:						be1[check_empty4[i]]++;

						if(be1[check_empty4[i]]>8)
							{
							macmaxbe1[check_empty4[i]] = Macmaxbe(3, 8);
							macminbe1[check_empty4[i]] = Macminbe(0, macmaxbe1[check_empty4[i]]);
							be1[check_empty4[i]] = macminbe1[check_empty4[i]];
							}
							
						nbf1[check_empty4[i]]++;
							
						if(nbf1[check_empty4[i]]>nb1[check_empty4[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request1[check_empty4[i]]==1)
								{
								req_fail_packet[check_empty4[i]]++;;
								}
							else
								{
								packet_drop[check_empty4[i]]++;
								nodes[check_empty4[i]].erase(nodes[check_empty4[i]].begin());
							        
							        if(delay_time[check_empty4[i]].size() > 0)
							        	{
							        delay_time[check_empty4[i]].erase(delay_time[check_empty4[i]].begin());
									}
								}

							if(nodes[check_empty4[i]].empty())
								{		
								wt2.at(check_empty4[i] - (no_of_sensors/4)) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe1[check_empty4[i]] = Macmaxbe(3, 8);
								macminbe1[check_empty4[i]] = Macminbe(0, macmaxbe1[check_empty4[i]]);
								be1[check_empty4[i]] = macminbe1[check_empty4[i]];
								nb1[check_empty4[i]] = nob(0, 5);
								nbf1[check_empty4[i]] = 0;
								wt2.at(check_empty4[i] - (no_of_sensors/4)) = clock() + random_be(pow(2, be1[check_empty4[i]]) - 1) * 320;
														
								if(wt2[check_empty4[i] - (no_of_sensors/4)]<(ct1 + tr[sensor_mintime4] + ack_tr))
									{
									goto C25;
									}
								else
									{
									it4 = check_empty4.begin();
									check_empty4.erase(it4+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wt2.at(check_empty4[i] - (no_of_sensors/4))=clock()+random_be(pow(2, be1[check_empty4[i]]) - 1) * 320;
							if(wt2[check_empty4[i] - (no_of_sensors/4)]<(ct1 + tr[sensor_mintime4] + ack_tr))
								{
								goto C25;
								}
							else
								{
								it4 = check_empty4.begin();
								check_empty4.erase(it4+i);
								}
							}
						}
					else
						{
						it4 = check_empty4.begin();
						check_empty4.erase(it4+i);
						}
					}	
				}
			}
										
		if((ct1 + tr[sensor_mintime4] + ack_tr)<((temp_c1+cap_so) - 3500))
			{	
			goto C23;
			}

cap_end_c2:	while(clock()<(temp_c1+cap_so)){}
			
		if(check_empty4.size() > 0)
			{	
			check_empty4.clear();	
			}
		}			
		
	for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
		{
		energy_consumption[i] = energy_consumption[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[4] = energy_consumption_aps[4] + (cap_so * idle);
	}
	
void csmaca5()
	{
	temp_c2 = clock();
	
	if(superframe_number % 4 == 1)
		{
		energy_consumption_aps[5] = energy_consumption_aps[5] + (32 * beacon_size * (tx - idle));

		for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
			{
			energy_consumption[i]= energy_consumption[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}
		}
		
	while(clock() < temp_c2 + (32 * beacon_size)){}
	
C31:	for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
		{
		if(!nodes[i].empty())
			{
			macmaxbe1[i] = Macmaxbe(3, 8);
			macminbe1[i] = Macminbe(0, macmaxbe1[i]);
			be1[i] = macminbe1[i];
			nb1[i] = nob(0, 5);
			nbf1[i] = 0;
			wait5.at(i-(no_of_sensors/2)) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
			}
		else
			{
			check_empty5.push_back(i);  
			wait5.at(i-(no_of_sensors/2)) = clock() + 17 * slot_length;			
			}
		}
		
	if(clock() > temp_c2 + cap_so - 3500){goto cap_end_c3;}

	if(check_empty5.size() == (no_of_sensors/4))
		{
		pit5 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
C32:		pit5 = pit5 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit5){}

		for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
			{
			if(!nodes[i].empty())
				{
				if(check_empty5.size() > 0)
					{	
					check_empty5.clear();	
					}

				goto C31;
				}
			}

		if(clock() > temp_c2 + cap_so - 3500){goto cap_end_c3;}		
	
		goto C32;
		}	
	
	for(int i=0; i<(no_of_sensors/4); i++)
		{
		wt3.at(i) = wait5[i]; 
		}
	
C33:	mintime5 = min_element(wt3);// waiting time with min value
	sensor_mintime5 = Mintime(wt3) + (no_of_sensors/2);// sensor id
	
	if(mintime5 < temp_c2 + cap_so - 3500)
		{
		while(mintime5 > clock()){}
		}
	else
		{
		goto cap_end_c3;
		}
		
	if(clock() < (temp_c2+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		ct2 = (double) clock();	
			
	 	if(!nodes[sensor_mintime5].empty())
			{
			if(request1[sensor_mintime5] != 1)
				{
				if(ber0[no_of_aps + sensor_mintime5][5] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[5] == 0 && lok[2] == 0)
						{
						lok[5] = 1;
						req_packet[sensor_mintime5]++;			
						request1[sensor_mintime5] = 1;
							
						for(int i=0; i<7; i++)
							{
							if(gts_id2[i] != 5 && gts_id0[i] != 2 && gts_id5[i] == no_of_sensors)
								{
								gts_id5[i] = sensor_mintime5;
								break;
								}
							}
						
						energy_consumption_aps[5] = energy_consumption_aps[5] + (352 * (tx - idle));
						energy_consumption[sensor_mintime5]= energy_consumption[sensor_mintime5]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet[sensor_mintime5]++;
						waste_energy[sensor_mintime5]= waste_energy[sensor_mintime5]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet[sensor_mintime5]++;	
					waste_energy[sensor_mintime5]= waste_energy[sensor_mintime5]+ (1920 * (tx-idle));
					}
	
				energy_consumption[sensor_mintime5]= energy_consumption[sensor_mintime5]+ (1920 * (tx-idle)); 
				energy_consumption_aps[5] = energy_consumption_aps[5] + (1920 * (rx - idle));
				ber_sensor1[sensor_mintime5] = ber_sensor1[sensor_mintime5] + ber0[no_of_aps + sensor_mintime5][5] * 64 * 8;			
				total_bit[sensor_mintime5] = total_bit[sensor_mintime5] + (64 * 8);
				}
			else
				{
				if(ber0[no_of_aps + sensor_mintime5][5] <= 0.5)
					{
					if(lok[5] == 0 && lok[2] == 0)
						{
						lok[5] = 1;
						clatency5 = clock() - delay_time[sensor_mintime5][0];
					
						if((no_of_sensors/2)<= sensor_mintime5 && sensor_mintime5 <(9*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime5][5] <= 0.1 && clatency5 <= pl1[sensor_mintime5])
							{
							ap5.data_type = 0;
							ap5.data_check = 0;
							check000++;	
							}
						else if((9*(no_of_sensors/16))<= sensor_mintime5 && sensor_mintime5 <(5*(no_of_sensors/8)) && ber0[no_of_aps + sensor_mintime5][5] <= 0.3 && clatency5 <= pl1[sensor_mintime5])
							{
							ap5.data_type = 1;
							ap5.data_check = 1;	
							check111++;
							}
						else if((5*(no_of_sensors/8))<= sensor_mintime5 && sensor_mintime5 <(11*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime5][5] <= 0.2 && clatency5 <= pl1[sensor_mintime5])
							{
							ap5.data_type = 2;
							ap5.data_check = 2;	
							check222++;
							}
						else if((11*(no_of_sensors/16))<= sensor_mintime5 && sensor_mintime5 <(3*(no_of_sensors/4)) && ber0[no_of_aps + sensor_mintime5][5] <= 0.5 && clatency5 <= pl1[sensor_mintime5])
							{
							ap5.data_type = 3;
							ap5.data_check = 3;	
							check333++;
							}
						else
							{
							if((no_of_sensors/2)<= sensor_mintime5 && sensor_mintime5 <(9*(no_of_sensors/16)))
								{
								ap5.data_type = 0;
								}
							else if((9*(no_of_sensors/16))<= sensor_mintime5 && sensor_mintime5 <(5*(no_of_sensors/8)))
								{
								ap5.data_type = 1;
								}
							else if((5*(no_of_sensors/8))<= sensor_mintime5 && sensor_mintime5 <(11*(no_of_sensors/16)))
								{
								ap5.data_type = 2;
								}
							else
								{
								ap5.data_type = 3;
								}
							
							ap5.data_check = 4;
							}
	
						if(ap5.data_type == ap5.data_check)
							{
							packet_count1[sensor_mintime5]++;
							
							if(ap5.data_check == 0)
								{
								valid000++;
								}
							else if(ap5.data_check == 1)
								{
								valid111++;
								}
							else if(ap5.data_check == 2)
								{
								valid222++;
								}
							else			
								{
								valid333++;
								}
 							}
						else
							{
							invalid[sensor_mintime5+7]++;
							waste_energy[sensor_mintime5]= waste_energy[sensor_mintime5]+ (tr[sensor_mintime5] * (tx-idle));
							}
	
						latency1[sensor_mintime5]= latency1[sensor_mintime5] + (clock() - delay_time[sensor_mintime5][0]);	
						ap5.latency = clock() - delay_time[sensor_mintime5][0];
						ap5.data_size = ps[sensor_mintime5];
						ap5.plife0 = nodes[sensor_mintime5][0].plife1 - clatency5;

						if(ap5.plife0 < 0)
							{
							checking++;
							}

						if(ap5.data_type == 0 || ap5.data_type == 1)
							{
							cd_count++;
							c_delay1[sensor_mintime5] = c_delay1[sensor_mintime5] + (clock() - delay_time[sensor_mintime5][0]);				
							}

						nodes[sensor_mintime5].erase(nodes[sensor_mintime5].begin());
						
						if(delay_time[sensor_mintime5].size() > 0)
							{
							delay_time[sensor_mintime5].erase(delay_time[sensor_mintime5].begin());
							}
	
						if(aps[5].size() >= buffer_size)
							{
							packet_drop_buffer_aps[5]++;
							aps[5].erase(aps[5].begin());
							
							if(delay_aps[5].size() > 0)
								{
								delay_aps[5].erase(delay_aps[5].begin());
								}
							}

						aps[5].push_back(ap5);
						delay_aps[5].push_back(clock());
						energy_consumption_aps[5] = energy_consumption_aps[5] + (32 * 11) * (tx - idle);
						energy_consumption[sensor_mintime5]= energy_consumption[sensor_mintime5]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						fail_packet[sensor_mintime5]++;
						nodes[sensor_mintime5][0].no_strans++;

						if(nodes[sensor_mintime5][0].no_strans > max_try)
							{
							packet_drop[sensor_mintime5]++;
							nodes[sensor_mintime5].erase(nodes[sensor_mintime5].begin());
							
							if(delay_time[sensor_mintime5].size() > 0)
								{
								delay_time[sensor_mintime5].erase(delay_time[sensor_mintime5].begin());
								}
							}
							
						waste_energy[sensor_mintime5]= waste_energy[sensor_mintime5]+ (tr[sensor_mintime5] * (tx-idle));	
						}
					}
				else
					{
					fail_packet[sensor_mintime5]++;
					nodes[sensor_mintime5][0].no_strans++;

					if(nodes[sensor_mintime5][0].no_strans > max_try)
						{
						packet_drop[sensor_mintime5]++;
						nodes[sensor_mintime5].erase(nodes[sensor_mintime5].begin());
						
						if(delay_time[sensor_mintime5].size() > 0)
							{
							delay_time[sensor_mintime5].erase(delay_time[sensor_mintime5].begin());
							}
						}
						
					waste_energy[sensor_mintime5]= waste_energy[sensor_mintime5]+ (tr[sensor_mintime5] * (tx-idle));	
					}
					
				energy_consumption[sensor_mintime5]= energy_consumption[sensor_mintime5]+ (tr[sensor_mintime5] * (tx-idle)); 
				energy_consumption_aps[5] = energy_consumption_aps[5] + (tr[sensor_mintime5] * (rx - idle));
				ber_sensor1[sensor_mintime5] = ber_sensor1[sensor_mintime5] + ber0[no_of_aps + sensor_mintime5][5] * ps[sensor_mintime5] * 8;	
				total_bit[sensor_mintime5] = total_bit[sensor_mintime5] + (ps[sensor_mintime5] * 8);
				}
			}
		else
			{
			wt3.at(sensor_mintime5 - (no_of_sensors/2)) = clock() + 17 * slot_length;
			
			if(ct2 < (temp_c2 + cap_so) - (tr[sensor_mintime5] + ack_tr))
				{	
				goto C33;
				}
			else
				{
				goto cap_end_c3;
				}
			}
			
		if(!nodes[sensor_mintime5].empty())
			{
			macmaxbe1[sensor_mintime5] = Macmaxbe(3, 8);
			macminbe1[sensor_mintime5] = Macminbe(0, macmaxbe1[sensor_mintime5]);
			be1[sensor_mintime5] = macminbe1[sensor_mintime5];
			nb1[sensor_mintime5] = nob(0, 5);
			nbf1[sensor_mintime5] = 0;
			wt3.at(sensor_mintime5 - (no_of_sensors/2))= clock() + random_be(pow(2, be1[sensor_mintime5]) - 1) * 320;
			}
		else
			{
			check_empty5.push_back(sensor_mintime5);  
			wt3.at(sensor_mintime5 - (no_of_sensors/2)) = clock() + 17 * slot_length;
			}	

		for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
			{
			if(i!=sensor_mintime5 && (!nodes[i].empty()) && wt3[i - (no_of_sensors/2)]<(ct2 + tr[sensor_mintime5] + ack_tr))
				{
C34:				be1[i]++;

				if(be1[i]>8)
					{
					macmaxbe1[i] = Macmaxbe(3, 8);
					macminbe1[i] = Macminbe(0, macmaxbe1[i]);
					be1[i] = macminbe1[i];
					}
					
				nbf1[i]++;
							
				if(nbf1[i]>nb1[i])
					{//transmission failure
					if(!request1[i]==1)
						{
						req_fail_packet[i]++;
						}
					else
						{
						packet_drop[i]++;
						nodes[i].erase(nodes[i].begin());
						
						if(delay_time[i].size() > 0)
							{
							delay_time[i].erase(delay_time[i].begin());
							}
						}
					
					if(nodes[i].empty())
						{
						check_empty5.push_back(i); 
						wt3.at(i - (no_of_sensors/2)) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe1[i] = Macmaxbe(3, 8);
						macminbe1[i] = Macminbe(0, macmaxbe1[i]);
						be1[i] = macminbe1[i];
						nb1[i] = nob(0, 5);
						nbf1[i] = 0;
						wt3.at(i - (no_of_sensors/2)) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
		
						if(wt3[i - (no_of_sensors/2)]<(ct2 + tr[sensor_mintime5] + ack_tr))
							{
							goto C34;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wt3.at(i - (no_of_sensors/2))= clock() + random_be(pow(2, be1[i]) - 1) * 320;

					if(wt3[i - (no_of_sensors/2)]<(ct2 + tr[sensor_mintime5] + ack_tr))
						{
						goto C34;
						}
					}														
				}
			}

		while(clock()<ct2+ tr[sensor_mintime5] + ack_tr){}
		
		lok[5] = 0;
		
		if(!check_empty5.empty())
			{
			for(int i=0; i<check_empty5.size(); i++)
				{
				if(!nodes[check_empty5[i]].empty())
					{
					macmaxbe1[check_empty5[i]] = Macmaxbe(3, 8);
					macminbe1[check_empty5[i]] = Macminbe(0, macmaxbe1[check_empty5[i]]);
					be1[check_empty5[i]] = macminbe1[check_empty5[i]];
					nb1[check_empty5[i]] = nob(0, 5);
					nbf1[check_empty5[i]] = 0;
					wt3.at(check_empty5[i] - (no_of_sensors/2)) = clock() + random_be(pow(2, be1[check_empty5[i]]) - 1) * 320;

					if(wt3.at(check_empty5[i] - (no_of_sensors/2))<(ct2+ tr[sensor_mintime5] + ack_tr))
						{									
C35:						be1[check_empty5[i]]++;

						if(be1[check_empty5[i]]>8)
							{
							macmaxbe1[check_empty5[i]] = Macmaxbe(3, 8);
							macminbe1[check_empty5[i]] = Macminbe(0, macmaxbe1[check_empty5[i]]);
							be1[check_empty5[i]] = macminbe1[check_empty5[i]];
							}
							
						nbf1[check_empty5[i]]++;
							
						if(nbf1[check_empty5[i]]>nb1[check_empty5[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request1[check_empty5[i]]==1)
								{
								req_fail_packet[check_empty5[i]]++;;
								}
							else
								{
								packet_drop[check_empty5[i]]++;
								nodes[check_empty5[i]].erase(nodes[check_empty5[i]].begin());
								
								if(delay_time[check_empty5[i]].size() > 0)
									{
							        delay_time[check_empty5[i]].erase(delay_time[check_empty5[i]].begin());
									}
								}

							if(nodes[check_empty5[i]].empty())
								{		
								wt3.at(check_empty5[i] - (no_of_sensors/2)) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe1[check_empty5[i]] = Macmaxbe(3, 8);
								macminbe1[check_empty5[i]] = Macminbe(0, macmaxbe1[check_empty5[i]]);
								be1[check_empty5[i]] = macminbe1[check_empty5[i]];
								nb1[check_empty5[i]] = nob(0, 5);
								nbf1[check_empty5[i]] = 0;
								wt3.at(check_empty5[i] - (no_of_sensors/2)) = clock() + random_be(pow(2, be1[check_empty5[i]]) - 1) * 320;														
								if(wt3[check_empty5[i] - (no_of_sensors/2)]<(ct2 + tr[sensor_mintime5] + ack_tr))
									{
									goto C35;
									}
								else
									{
									it5 = check_empty5.begin();
									check_empty5.erase(it5+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wt3.at(check_empty5[i] - (no_of_sensors/2))=clock()+random_be(pow(2, be1[check_empty5[i]]) - 1) * 320;
							if(wt3[check_empty5[i] - (no_of_sensors/2)]<(ct2 + tr[sensor_mintime5] + ack_tr))
								{
								goto C35;
								}
							else
								{
								it5 = check_empty5.begin();
								check_empty5.erase(it5+i);
								}
							}
						}
					else
						{
						it5 = check_empty5.begin();
						check_empty5.erase(it5+i);
						}
					}
				}
			}
										
		if((ct2 + tr[sensor_mintime5] + ack_tr)<((temp_c2+cap_so) - 3500))
			{	
			goto C33;
			}

cap_end_c3:	while(clock()<(temp_c2+cap_so)){}
			
		if(check_empty5.size() > 0)
			{	
			check_empty5.clear();	
			}
		}			
		
	for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
		{
		energy_consumption[i] = energy_consumption[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[5] = energy_consumption_aps[5] + (cap_so * idle);
	}		
	
void csmaca6()
	{
	temp_c3 = clock();
	
	if(superframe_number % 4 == 1)
		{
		energy_consumption_aps[6] = energy_consumption_aps[6] + (32 * beacon_size * (tx - idle));

		for(int i=(3*(no_of_sensors/4)); i<no_of_sensors; i++)
			{
			energy_consumption[i]= energy_consumption[i]+ (32 * beacon_size * (rx-idle)); //1 byte tx in 32 micro-sec
			}
		}
		
	while(clock() < temp_c3 + (32 * beacon_size)){}
	
C41:	for(int i=(3*(no_of_sensors/4)); i<no_of_sensors; i++)
		{
		if(!nodes[i].empty())
			{
			macmaxbe1[i] = Macmaxbe(3, 8);
			macminbe1[i] = Macminbe(0, macmaxbe1[i]);
			be1[i] = macminbe1[i];
			nb1[i] = nob(0, 5);
			nbf1[i] = 0;
			wait6.at(i - (3*(no_of_sensors/4))) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
			}
		else
			{
			check_empty6.push_back(i);  
			wait6.at(i - (3*(no_of_sensors/4))) = clock() + 17 * slot_length;			
			}
		}
		
	if(clock() > temp_c3 + cap_so - 3500){goto cap_end_c4;}

	if(check_empty6.size() == (no_of_sensors/4))
		{
		pit6 = clock(); // 10000= 1000000/100, time required to generate 1 packet in ms if pgr is 100
C42:		pit6 = pit6 + 3500; // 35000= time required to generate first packet

		while(clock()<=pit6){}

		for(int i=0; i<(no_of_sensors/4); i++)
			{
			if(!nodes[i].empty())
				{
				if(check_empty6.size() > 0)
					{	
					check_empty6.clear();	
					}

				goto C41;
				}
			}

		if(clock() > temp_c3 + cap_so-3500){goto cap_end_c4;}		
	
		goto C42;
		}	
	
	for(int i=0; i<(no_of_sensors/4); i++)
		{
		wt4.at(i) = wait6[i]; 
		}
		
C43:	mintime6 = min_element(wt4);// waiting time with min value
	sensor_mintime6 = Mintime(wt4) + (3*(no_of_sensors/4));// sensor id
	
	if(mintime6 < temp_c3 + cap_so-3500)
		{
		while(mintime6 > clock()){}
		}
	else
		{
		goto cap_end_c4;
		}
		
	if(clock() < (temp_c3+cap_so-3500))
		{//int tr = (ps[sensor_mintime] * 1000000) / dtr[sensor_mintime]; 
		ct3 = (double) clock();	
			
	 	if(!nodes[sensor_mintime6].empty())
			{
			if(request1[sensor_mintime6] != 1)
				{
				if(ber0[no_of_aps + sensor_mintime6][6] <= 0.5)
					{//req_packet_count[sensor_mintime]++;
					if(lok[6] == 0 && lok[2] == 0)
						{
						lok[6] = 1;
						req_packet[sensor_mintime6]++;				
						request1[sensor_mintime6] = 1;
							
						for(int i=0; i<7; i++)
							{
							if(gts_id2[i] != 6 && gts_id0[i] != 2 && gts_id6[i] == no_of_sensors)
								{
								gts_id6[i] = sensor_mintime6;
								break;
								}
							}
							
						energy_consumption_aps[6] = energy_consumption_aps[6] + (352 * (tx - idle));
						energy_consumption[sensor_mintime6]= energy_consumption[sensor_mintime6]+ (352 * (rx-idle));
						}
					else
						{
						req_fail_packet[sensor_mintime6]++;
						waste_energy[sensor_mintime6]= waste_energy[sensor_mintime6]+ (1920 * (tx-idle));
						}	
					}
				else
					{
					req_fail_packet[sensor_mintime6]++;
					waste_energy[sensor_mintime6]= waste_energy[sensor_mintime6]+ (1920 * (tx-idle));	
					}

				energy_consumption[sensor_mintime6]= energy_consumption[sensor_mintime6]+ (1920 * (tx-idle)); 
				energy_consumption_aps[6] = energy_consumption_aps[6] + (1920 * (rx - idle));
				ber_sensor1[sensor_mintime6] = ber_sensor1[sensor_mintime6] + ber0[no_of_aps + sensor_mintime6][6] * 64 * 8;	
				total_bit[sensor_mintime6] = total_bit[sensor_mintime6] + (64 * 8);		
				}
			else
				{
				if(ber0[no_of_aps + sensor_mintime6][6] <= 0.5)
					{
					if(lok[6] == 0 && lok[2] == 0)
						{
						lok[6] = 1;
						clatency6 = clock() - delay_time[sensor_mintime6][0];
					
						if((3*(no_of_sensors/4))<= sensor_mintime6 && sensor_mintime6 <(13*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime6][6] <= 0.1 && clatency6 <= pl1[sensor_mintime6])
							{
							ap6.data_type = 0;
							ap6.data_check = 0;
							check000++;	
							}
						else if((13*(no_of_sensors/16))<= sensor_mintime6 && sensor_mintime6 <(7*(no_of_sensors/8)) && ber0[no_of_aps + sensor_mintime6][6] <= 0.3 && clatency6 <= pl1[sensor_mintime6])
							{
							ap6.data_type = 1;
							ap6.data_check = 1;
							check111++;	
							}
						else if((7*(no_of_sensors/8))<= sensor_mintime6 && sensor_mintime6 <(15*(no_of_sensors/16)) && ber0[no_of_aps + sensor_mintime6][6] <= 0.2 && clatency6 <= pl1[sensor_mintime6])
							{
							ap6.data_type = 2;
							ap6.data_check = 2;
							check222++;	
							}
						else if((15*(no_of_sensors/16))<= sensor_mintime6 && sensor_mintime6 < no_of_sensors && ber0[no_of_aps + sensor_mintime6][6] <= 0.5 && clatency6 <= pl1[sensor_mintime6])
							{
							ap6.data_type = 3;
							ap6.data_check = 3;
							check333++;	
							}
						else
							{
							if((3*(no_of_sensors/4))<= sensor_mintime6 && sensor_mintime6 <(13*(no_of_sensors/16)))
								{
								ap6.data_type = 0;
								}
							else if((13*(no_of_sensors/16))<= sensor_mintime6 && sensor_mintime6 <(7*(no_of_sensors/8)))
								{
								ap6.data_type = 1;
								}
							else if((7*(no_of_sensors/8))<= sensor_mintime6 && sensor_mintime6 <(15*(no_of_sensors/16)))
								{
								ap6.data_type = 2;
								}
							else
								{
								ap6.data_type = 3;
								}
							
							ap6.data_check = 4;
							}
	
						if(ap6.data_type == ap6.data_check)
							{
							packet_count1[sensor_mintime6]++;
							
							if(ap6.data_check == 0)
								{
								valid000++;
								}
							else if(ap6.data_check == 1)
								{
								valid111++;
								}
							else if(ap6.data_check == 2)
								{
								valid222++;
								}
							else			
								{
								valid333++;
								}
 							}
						else
							{
							invalid[sensor_mintime6+7]++;
							waste_energy[sensor_mintime6]= waste_energy[sensor_mintime6]+ (tr[sensor_mintime6] * (tx-idle));
							}
	
						latency1[sensor_mintime6]= latency1[sensor_mintime6] + (clock() - delay_time[sensor_mintime6][0]);	
						ap6.latency = clock() - delay_time[sensor_mintime6][0];
						ap6.data_size = ps[sensor_mintime6];
						ap6.plife0 = nodes[sensor_mintime6][0].plife1 - clatency6;

						if(ap6.plife0 < 0)
							{
							checking++;
							}

						if(ap6.data_type == 0 || ap6.data_type == 1)
							{
							cd_count++;
							c_delay1[sensor_mintime6] = c_delay1[sensor_mintime6] + (clock() - delay_time[sensor_mintime6][0]);				
							}

						nodes[sensor_mintime6].erase(nodes[sensor_mintime6].begin());
						
						if(delay_time[sensor_mintime6].size() > 0)
							{
							delay_time[sensor_mintime6].erase(delay_time[sensor_mintime6].begin());
							}	
		
						if(aps[6].size() >= buffer_size)
							{
							packet_drop_buffer_aps[6]++;
							aps[6].erase(aps[6].begin());
							
							if(delay_aps[6].size() > 0)
								{
								delay_aps[6].erase(delay_aps[6].begin());
								}
							}

						aps[6].push_back(ap6);
						delay_aps[6].push_back(clock());
						energy_consumption_aps[6] = energy_consumption_aps[6] + (32 * 11) * (tx - idle);
						energy_consumption[sensor_mintime6]= energy_consumption[sensor_mintime6]+ ((32 * 11) * (rx - sleepp));
						}
					else
						{
						fail_packet[sensor_mintime6]++;
						nodes[sensor_mintime6][0].no_strans++;

						if(nodes[sensor_mintime6][0].no_strans > max_try)
							{
							packet_drop[sensor_mintime6]++;
							nodes[sensor_mintime6].erase(nodes[sensor_mintime6].begin());
							
							if(delay_time[sensor_mintime6].size() > 0)
								{
								delay_time[sensor_mintime6].erase(delay_time[sensor_mintime6].begin());
								}
							}
							
						waste_energy[sensor_mintime6]= waste_energy[sensor_mintime6]+ (tr[sensor_mintime6] * (tx-idle));	
						}	
					}
				else
					{
					fail_packet[sensor_mintime6]++;
					nodes[sensor_mintime6][0].no_strans++;

					if(nodes[sensor_mintime6][0].no_strans > max_try)
						{
						packet_drop[sensor_mintime6]++;
						nodes[sensor_mintime6].erase(nodes[sensor_mintime6].begin());
						
						if(delay_time[sensor_mintime6].size() > 0)
							{
							delay_time[sensor_mintime6].erase(delay_time[sensor_mintime6].begin());
							}
						}
						
					waste_energy[sensor_mintime6]= waste_energy[sensor_mintime6]+ (tr[sensor_mintime6] * (tx-idle));	
					}
				
				energy_consumption[sensor_mintime6]= energy_consumption[sensor_mintime6]+ (tr[sensor_mintime6] * (tx-idle)); 
				energy_consumption_aps[6] = energy_consumption_aps[6] + (tr[sensor_mintime6] * (rx - idle));
				ber_sensor1[sensor_mintime6] = ber_sensor1[sensor_mintime6] + ber0[no_of_aps + sensor_mintime6][6] * ps[sensor_mintime6] * 8;
				total_bit[sensor_mintime6] = total_bit[sensor_mintime6] + (ps[sensor_mintime6] * 8);	
				}
			}
		else
			{
			wt4.at(sensor_mintime6 - (3*(no_of_sensors/4))) = clock() + 17 * slot_length;
			
			if(ct3 < (temp_c3 + cap_so) - (tr[sensor_mintime6] + ack_tr))
				{	
				goto C43;
				}
			else
				{
				goto cap_end_c4;
				}
			}
		
		if(!nodes[sensor_mintime6].empty())
			{
			macmaxbe1[sensor_mintime6] = Macmaxbe(3, 8);
			macminbe1[sensor_mintime6] = Macminbe(0, macmaxbe1[sensor_mintime6]);
			be1[sensor_mintime6] = macminbe1[sensor_mintime6];
			nb1[sensor_mintime6] = nob(0, 5);
			nbf1[sensor_mintime6] = 0;
			wt4.at(sensor_mintime6 - (3*(no_of_sensors/4)))= clock() + random_be(pow(2, be1[sensor_mintime6]) - 1) * 320;
			}
		else
			{
			check_empty6.push_back(sensor_mintime6);  
			wt4.at(sensor_mintime6 - (3*(no_of_sensors/4))) = clock() + 17 * slot_length;
			}	

		for(int i=(3*(no_of_sensors/4)); i<no_of_sensors; i++)
			{
			if(i!=sensor_mintime6 && (!nodes[i].empty()) && wt4[i - (3*(no_of_sensors/4))]< (ct3 + tr[sensor_mintime6] + ack_tr) )
				{
C44:				be1[i]++;

				if(be1[i]>8)
					{
					macmaxbe1[i] = Macmaxbe(3, 8);
					macminbe1[i] = Macminbe(0, macmaxbe1[i]);
					be1[i] = macminbe1[i];
					}
					
				nbf1[i]++;
						
				if(nbf1[i]>nb1[i])
					{//transmission failure
					if(!request1[i]==1)
						{
						req_fail_packet[i]++;
						}
					else
						{
						packet_drop[i]++;
						nodes[i].erase(nodes[i].begin());
						
						if(delay_time[i].size() > 0)
							{
							delay_time[i].erase(delay_time[i].begin());
							}
						}
					
					if(nodes[i].empty())
						{
						check_empty6.push_back(i); 
						wt4.at(i - (3*(no_of_sensors/4))) = clock() + 17 * slot_length;
						}
					else
						{
						macmaxbe1[i] = Macmaxbe(3, 8);
						macminbe1[i] = Macminbe(0, macmaxbe1[i]);
						be1[i] = macminbe1[i];
						nb1[i] = nob(0, 5);
						nbf1[i] = 0;
						wt4.at(i - (3*(no_of_sensors/4))) = clock() + random_be(pow(2, be1[i]) - 1) * 320;
		
						if(wt4[i - (3*(no_of_sensors/4))]<(ct3 + tr[sensor_mintime6] + ack_tr))
							{
							goto C44;
							}
						}
					}
				else
					{//update waiting_time of sensor id i
					wt4.at(i - (3*(no_of_sensors/4))) = clock() + random_be(pow(2, be1[i]) - 1) * 320;

					if(wt4[i- (3*(no_of_sensors/4))]<(ct3 + tr[sensor_mintime6] + ack_tr))
						{
						goto C44;
						}
					}														
				}
			}

		while(clock()<ct3+ tr[sensor_mintime6] + ack_tr){}
		
		lok[6] = 0;

		if(!check_empty6.empty())
			{
			for(int i=0; i<check_empty6.size(); i++)
				{
				if(!nodes[check_empty6[i]].empty())
					{
					macmaxbe1[check_empty6[i]] = Macmaxbe(3, 8);
					macminbe1[check_empty6[i]] = Macminbe(0, macmaxbe1[check_empty6[i]]);
					be1[check_empty6[i]] = macminbe1[check_empty6[i]];
					nb1[check_empty6[i]] = nob(0, 5);
					nbf1[check_empty6[i]] = 0;
					wt4.at(check_empty6[i] - (3*(no_of_sensors/4))) = clock() + random_be(pow(2, be1[check_empty6[i]]) - 1) * 320;

					if(wt4.at(check_empty6[i] - (3*(no_of_sensors/4)))<(ct3 + tr[sensor_mintime6] + ack_tr))
						{									
C45:						be1[check_empty6[i]]++;

						if(be1[check_empty6[i]]>8)
							{
							macmaxbe1[check_empty6[i]] = Macmaxbe(3, 8);
							macminbe1[check_empty6[i]] = Macminbe(0, macmaxbe1[check_empty6[i]]);
							be1[check_empty6[i]] = macminbe1[check_empty6[i]];
							}
							
						nbf1[check_empty6[i]]++;
							
						if(nbf1[check_empty6[i]]>nb1[check_empty6[i]])
							{//cout<<"transmission failure"<<endl;  
							if(!request1[check_empty6[i]]==1)
								{
								req_fail_packet[check_empty6[i]]++;;
								}
							else
								{
								packet_drop[check_empty6[i]]++;
								nodes[check_empty6[i]].erase(nodes[check_empty6[i]].begin());
								
								if(delay_time[check_empty6[i]].size() > 0)
									{
							             delay_time[check_empty6[i]].erase(delay_time[check_empty6[i]].begin());
									}
								}

							if(nodes[check_empty6[i]].empty())
								{		
								wt4.at(check_empty6[i] - (3*(no_of_sensors/4))) = clock() + 17 * slot_length;	
								}
							else
								{
								macmaxbe1[check_empty6[i]] = Macmaxbe(3, 8);
								macminbe1[check_empty6[i]] = Macminbe(0, macmaxbe1[check_empty6[i]]);
								be1[check_empty6[i]] = macminbe1[check_empty6[i]];
								nb1[check_empty6[i]] = nob(0, 5);
								nbf1[check_empty6[i]] = 0;
								wt4.at(check_empty6[i] - (3*(no_of_sensors/4))) = clock() + random_be(pow(2, be1[check_empty6[i]]) - 1) * 320;
														
								if(wt4[check_empty6[i] - (3*(no_of_sensors/4))]<(ct3 + tr[sensor_mintime6] + ack_tr))
									{
									goto C45;
									}
								else
									{
									it6 = check_empty6.begin();
									check_empty6.erase(it6+i);
									}
								}
							}
						else
							{//cout<<"update waiting_time of sensor id i"<<endl;
							wt4.at(check_empty6[i] - (3*(no_of_sensors/4)))=clock()+random_be(pow(2, be1[check_empty6[i]]) - 1) * 320;

							if(wt4[check_empty6[i] - (3*(no_of_sensors/4))]<(ct3 + tr[sensor_mintime6] + ack_tr))
								{
								goto C45;
								}
							else
								{
								it6 = check_empty6.begin();
								check_empty6.erase(it6+i);
								}
							}
						}
					else
						{
						it6 = check_empty6.begin();
						check_empty6.erase(it6+i);
						}
					}	
				}
			}
									
		if((ct3 + tr[sensor_mintime6] + ack_tr)<((temp_c3+cap_so) - 3500))
			{	
			goto C43;
			}

cap_end_c4:	while(clock()<(temp_c3+cap_so)){}
			
		if(check_empty6.size() > 0)
			{	
			check_empty6.clear();	
			}
		}			
		
	for(int i=(3*(no_of_sensors/4)); i<no_of_sensors; i++)
		{
		energy_consumption[i] = energy_consumption[i] + (cap_so * idle);
		}
		
	energy_consumption_aps[6] = energy_consumption_aps[6] + (cap_so * idle);
	}
		
void gts0()
	{// update avg. ber, transmission time(ACK), energy consumption.
	for(int i=0; i<7; i++) //gts number start
		{
		gts_t0 = clock();
		id0 = gts_id0[i];
		
		if(id0 == 0)
			{
			goto end_gts_p1;
			}

		if((i%4) == 0)
			{
			gber0 = ber0[id0][0];
			}
		else if((i%4) == 1)
			{
			gber0 = ber1[id0][0];
			}
		else if((i%4) == 2)
			{
			gber0 = ber2[id0][0];
			}
		else
			{
			gber0 = ber3[id0][0];
			}
			
		cui_ber[0] = cui_ber[0] + gber0;
		cui_gts[0]++; 	
		
		if(clock()<((gts_t0+slot_length)-3500))
			{
GP11:			emg_t0 = clock();
			
			if(!aps[id0].empty())
				{
				if(gber0 <= 0.5)
					{	
					clatency0 = clock() - delay_aps[id0][0];
					
					if(aps[id0][0].data_type == 0 && gber0 <= 0.1 && clatency0 <= aps[id0][0].plife0)
						{
						ap0.data_type = 0;
						check0++;
						
						if(aps[id0][0].data_check != 4)
							{
							ap0.data_check = 0;
							}
						else
							{
							ap0.data_check = 4;
							}
						}
					else if(aps[id0][0].data_type == 1 && gber0 <= 0.3 && clatency0 <= aps[id0][0].plife0)
						{
						ap0.data_type = 1;
						check1++;
						
						if(aps[id0][0].data_check != 4)
							{
							ap0.data_check = 1;
							}
						else
							{
							ap0.data_check = 4;
							}
						}
					else if(aps[id0][0].data_type == 2 && gber0 <= 0.2 && clatency0 <= aps[id0][0].plife0)
						{
						ap0.data_type = 2;
						check2++;
						
						if(aps[id0][0].data_check != 4)
							{
							ap0.data_check = 2;
							}
						else
							{
							ap0.data_check = 4;
							}
						}
					else if(aps[id0][0].data_type == 3 && gber0 <= 0.5 && clatency0 <= aps[id0][0].plife0)
						{
						ap0.data_type = 3;
						check3++;
						
						if(aps[id0][0].data_check != 4)
							{
							ap0.data_check = 3;
							}
						else
							{
							ap0.data_check = 4;
							}
						}
					else
						{
						ap0.data_type = aps[id0][0].data_type;
						ap0.data_check = 4;
						}

					if(ap0.data_type == ap0.data_check)
						{test0++;
						packet_count0[id0]++; 
						
						if(ap0.data_check == 0)
							{
							valid0++;
							}
						else if(ap0.data_check == 1)
							{
							valid1++;
							}
						else if(ap0.data_check == 2)
							{
							valid2++;
							}
						else			
							{
							valid3++;
							}
						}
					else
						{
						invalid[id0]++;
						waste_energy[id0]= waste_energy[id0]+ (31.25 * aps[id0][0].data_size * (tx-sleepp));
						}

					latency0[id0]= latency0[id0] + (clock() - delay_aps[id0][0]);	
					ap0.latency = clock() - delay_aps[id0][0] + aps[id0][0].latency;
					ap0.data_size = aps[id0][0].data_size;
					data_siz[id0] = aps[id0][0].data_size;
					ap0.plife0 = aps[id0][0].plife0 - clatency0;

					if(ap0.plife0 < 0)
						{
						checking++;
						}

					if(ap0.data_type == 0 || ap0.data_type == 1)
						{
						cd_count++;
						c_delay0[id0] = c_delay0[id0] + (clock() - delay_aps[id0][0]);				
						}

					if(ap0.data_type == 0 || ap0.data_type == 2)
						{
						r_ber0 = r_ber0 + data_siz[id0] * gber0 * 8;
						r_count0 = r_count0 + data_siz[id0] * 8;	
						}

					aps[id0].erase(aps[id0].begin());
					
					if(delay_aps[id0].size() > 0)
						{
						delay_aps[id0].erase(delay_aps[id0].begin());
						}

					if(aps[0].size() >= buffer_size)
						{
						packet_drop_buffer_aps[0]++;
						aps[0].erase(aps[0].begin());
						
						if(delay_aps[0].size() > 0)
							{
							delay_aps[0].erase(delay_aps[0].begin());
							}
						}

					aps[0].push_back(ap0);
					delay_aps[0].push_back(clock());
					energy_consumption_aps[0] = energy_consumption_aps[0] + (32 * 11) * (tx - idle);
					energy_consumption_aps[id0]= energy_consumption_aps[id0]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet_aps[id0]++;
					aps[id0][0].no_ctrans++;
					data_siz[id0] = aps[id0][0].data_size;

					if(aps[id0][0].no_ctrans > max_try)
						{
						packet_drop_aps[id0]++;
						aps[id0].erase(aps[id0].begin());
						
						if(delay_aps[id0].size() > 0)
							{
							delay_aps[id0].erase(delay_aps[id0].begin());
							}
						}
						
					waste_energy[id0]= waste_energy[id0]+ (31.25 * data_siz[id0] * (tx-sleepp));	
					}
					
				energy_consumption[id0]= energy_consumption[id0]+ (31.25 * data_siz[id0] * (tx-sleepp)); 
				energy_consumption_aps[0] = energy_consumption_aps[0] + 31.25 * data_siz[id0] * (rx - idle);				
				ber_sensor0[id0] = ber_sensor0[id0] + ps[id0] * gber0 * 8;
				total_bit[id0] = total_bit[id0] + data_siz[id0] * 8;
				gts_ber0 = gts_ber0 + data_siz[id0] * gber0 * 8;
				gts_pcount0 = gts_pcount0 + data_siz[id0] * 8;
				
				while(clock()<(emg_t0+(31.25 * ap0.data_size)+ack_tr)){}		
				}
			else
				{
				waste_energy1[id0]= waste_energy1[id0]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_t0+2500){}
				}			
					
			if(!aps[id0].empty() && clock()<((gts_t0+slot_length) - 3500))
				{
				goto GP11;
				}
			}	
			
end_gts_p1:	while(clock() < (gts_t0 + slot_length)){}		
		}

	for(int i=1; i<3; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[0] = energy_consumption_aps[0] + (7 * slot_length * idle);
	}
	
void gts1()
	{// update avg. ber, transmission time(ACK), energy consumption.
	for(int i=0; i<7; i++) //gts number start
		{
		gts_t1 = clock();
		id1 = gts_id1[i];
		
		if(id1 == 0)
			{
			goto end_gts_p2;
			}

		if((i%4) == 0)
			{
			gber1 = ber0[id1][1];
			}
		else if((i%4) == 1)
			{
			gber1 = ber1[id1][1];
			}
		else if((i%4) == 2)
			{
			gber1 = ber2[id1][1];
			}
		else
			{
			gber1 = ber3[id1][1];
			}
			
		cui_ber[1] = cui_ber[1] + gber1;
		cui_gts[1]++;	
		
		if(clock()<((gts_t1+slot_length)-3500))
			{
GP12:			emg_t1 = clock();
			
			if(!aps[id1].empty())
				{
				if(gber1 <= 0.5)
					{	
					clatency1 = clock() - delay_aps[id1][0];
					
					if(aps[id1][0].data_type == 0 && gber1 <= 0.1 && clatency1 <= aps[id1][0].plife0)
						{
						ap1.data_type = 0;
						check00++;
						
						if(aps[id1][0].data_check != 4)
							{
							ap1.data_check = 0;
							}
						else
							{
							ap1.data_check = 4;
							}
						}
					else if(aps[id1][0].data_type == 1 && gber1 <= 0.3 && clatency1 <= aps[id1][0].plife0)
						{
						ap1.data_type = 1;
						check11++;
						
						if(aps[id1][0].data_check != 4)
							{
							ap1.data_check = 1;
							}
						else
							{
							ap1.data_check = 4;
							}
						}
					else if(aps[id1][0].data_type == 2 && gber1 <= 0.2 && clatency1 <= aps[id1][0].plife0)
						{
						ap1.data_type = 2;
						check22++;
						
						if(aps[id1][0].data_check != 4)
							{
							ap1.data_check = 2;
							}
						else
							{
							ap1.data_check = 4;
							}
						}
					else if(aps[id1][0].data_type == 3 && gber1 <= 0.5 && clatency1 <= aps[id1][0].plife0)
						{
						ap1.data_type = 3;
						check33++;
						
						if(aps[id1][0].data_check != 4)
							{
							ap1.data_check = 3;
							}
						else
							{
							ap1.data_check = 4;
							}
						}
					else
						{
						ap1.data_type = aps[id1][0].data_type;
						ap1.data_check = 4;
						}

					if(ap1.data_type == ap1.data_check)
						{test1++;
						packet_count0[id1]++; 
						
						if(ap1.data_check == 0)
							{
							valid00++;
							}
						else if(ap1.data_check == 1)
							{
							valid11++;
							}
						else if(ap1.data_check == 2)
							{
							valid22++;
							}
						else			
							{
							valid33++;
							}
						}
					else
						{
						invalid[id1]++;
						waste_energy[id1]= waste_energy[id1]+ (31.25 * aps[id1][0].data_size * (tx-sleepp));
						}

					latency0[id1]= latency0[id1] + (clock() - delay_aps[id1][0]);	
					ap1.latency = clock() - delay_aps[id1][0] + aps[id1][0].latency;
					ap1.data_size = aps[id1][0].data_size;
					data_siz[id1] = aps[id1][0].data_size;
					ap1.plife0 = aps[id1][0].plife0 - clatency1;

					if(ap1.plife0 < 0)
						{
						checking++;
						}

					if(ap1.data_type == 0 || ap1.data_type == 1)
						{
						cd_count++;
						c_delay0[id1] = c_delay0[id1] + (clock() - delay_aps[id1][0]);				
						}

					if(ap1.data_type == 0 || ap1.data_type == 2)
						{
						r_ber1 = r_ber1 + data_siz[id1] * gber1 * 8;
						r_count1 = r_count1 + data_siz[id1] * 8;	
						}

					aps[id1].erase(aps[id1].begin());
					
					if(delay_aps[id1].size() > 0)
						{
						delay_aps[id1].erase(delay_aps[id1].begin());
						}
	
					if(aps[1].size() >= buffer_size)
						{
						packet_drop_buffer_aps[1]++;
						aps[1].erase(aps[1].begin());
						
						if(delay_aps[1].size() > 0)
							{
							delay_aps[1].erase(delay_aps[1].begin());
							}
						}

					aps[1].push_back(ap1);
					delay_aps[1].push_back(clock());					
					energy_consumption_aps[1] = energy_consumption_aps[1] + (32 * 11) * (tx - idle);
					energy_consumption_aps[id1]= energy_consumption_aps[id1]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet_aps[id1]++;
					aps[id1][0].no_ctrans++;
					data_siz[id1] = aps[id1][0].data_size;

					if(aps[id1][0].no_ctrans > max_try)
						{
						packet_drop_aps[id1]++;
						aps[id1].erase(aps[id1].begin());
						
						if(delay_aps[id1].size() > 0)
							{
							delay_aps[id1].erase(delay_aps[id1].begin());
							}
						}
						
					waste_energy[id1]= waste_energy[id1]+ (31.25 * data_siz[id1] * (tx-sleepp));	
					}
					
				energy_consumption[id1]= energy_consumption[id1]+ (31.25 * data_siz[id1] * (tx-sleepp)); 
				energy_consumption_aps[1] = energy_consumption_aps[1] + 31.25 * data_siz[id1] * (rx - idle);				
				ber_sensor0[id1] = ber_sensor0[id1] + data_siz[id1] * gber1 * 8;
				total_bit[id1] = total_bit[id1] + data_siz[id1] * 8;
				gts_ber1 = gts_ber1 + data_siz[id1] * gber1 * 8;
				gts_pcount1 = gts_pcount1 + data_siz[id1] * 8;
	
				while(clock()<(emg_t1+(31.25 * ap1.data_size)+ack_tr)){}		
				}
			else
				{
				waste_energy1[id1]= waste_energy1[id1]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_t1+2500){}
				}			
						
			if(!aps[id1].empty() && clock()<((gts_t1+slot_length) - 3500))
				{
				goto GP12;
				}
			}	
			
end_gts_p2:	while(clock() < (gts_t1 + slot_length)){}		
		}

	for(int i=3; i<5; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[1] = energy_consumption_aps[1] + (7 * slot_length * idle);
	}
	
void gts2()
	{// update avg. ber, transmission time(ACK), energy consumption.
	for(int i=0; i<7; i++) //gts number start
		{
		gts_t2 = clock();
		id2 = gts_id2[i];
		
		if(id2 == 0)
			{
			goto end_gts_p3;
			}

		if((i%4) == 0)
			{
			gber2 = ber0[id2][2];
			}
		else if((i%4) == 1)
			{
			gber2 = ber1[id2][2];
			}
		else if((i%4) == 2)
			{
			gber2 = ber2[id2][2];
			}
		else
			{
			gber2 = ber3[id2][2];
			}
			
		cui_ber[2] = cui_ber[2] + gber2;
		cui_gts[2]++;	
		
		if(clock()<((gts_t2+slot_length)-3500))
			{
GP13:			emg_t2 = clock();
			
			if(!aps[id2].empty())
				{
				if(gber2 <= 0.5)
					{	
					clatency2 = clock() - delay_aps[id2][0];
					
					if(aps[id2][0].data_type == 0 && gber2 <= 0.1 && clatency2 <= aps[id2][0].plife0)
						{
						ap2.data_type = 0;
						check00++;
						
						if(aps[id2][0].data_check != 4)
							{
							ap2.data_check = 0;
							}
						else
							{
							ap2.data_check = 4;
							}
						}
					else if(aps[id2][0].data_type == 1 && gber2 <= 0.3 && clatency2 <= aps[id2][0].plife0)
						{
						ap2.data_type = 1;
						check11++;
						
						if(aps[id2][0].data_check != 4)
							{
							ap2.data_check = 1;
							}
						else
							{
							ap2.data_check = 4;
							}
						}
					else if(aps[id2][0].data_type == 2 && gber2 <= 0.2 && clatency2 <= aps[id2][0].plife0)
						{
						ap2.data_type = 2;
						check22++;						

						if(aps[id2][0].data_check != 4)
							{
							ap2.data_check = 2;
							}
						else
							{
							ap2.data_check = 4;
							}
						}
					else if(aps[id2][0].data_type == 3 && gber2 <= 0.5 && clatency2 <= aps[id2][0].plife0)
						{
						ap2.data_type = 3;
						check33++;
						
						if(aps[id2][0].data_check != 4)
							{
							ap2.data_check = 3;
							}
						else
							{
							ap2.data_check = 4;
							}
						}
					else
						{
						ap2.data_type = aps[id2][0].data_type;
						ap2.data_check = 4;
						}

					if(ap2.data_type == ap2.data_check)
						{test2++;
						packet_count0[id2]++; 
						
						if(ap2.data_check == 0)
							{
							valid00++;
							}
						else if(ap2.data_check == 1)
							{
							valid11++;
							}
						else if(ap2.data_check == 2)
							{
							valid22++;
							}
						else			
							{
							valid33++;
							}
						}
					else
						{
						invalid[id2]++;
						waste_energy[id2]= waste_energy[id2]+ (31.25 * aps[id2][0].data_size * (tx-sleepp));
						}

					latency0[id2]= latency0[id2] + (clock() - delay_aps[id2][0]);	
					ap2.latency = clock() - delay_aps[id2][0] + aps[id2][0].latency;
					ap2.data_size = aps[id2][0].data_size;
					data_siz[id2] = aps[id2][0].data_size;
					ap2.plife0 = aps[id2][0].plife0 - clatency2;

					if(ap2.plife0 < 0)
						{
						checking++;
						}

					if(ap2.data_type == 0 || ap2.data_type == 1)
						{
						cd_count++;
						c_delay0[id2] = c_delay0[id2] + (clock() - delay_aps[id2][0]);				
						}

					if(ap2.data_type == 0 || ap2.data_type == 2)
						{
						r_ber2 = r_ber2 + data_siz[id2] * gber2 * 8;
						r_count2 = r_count2 + data_siz[id2] * 8;	
						}

					aps[id2].erase(aps[id2].begin());
					
					if(delay_aps[id2].size() > 0)
						{
						delay_aps[id2].erase(delay_aps[id2].begin());
						}

					if(aps[2].size() >= buffer_size)
						{
						packet_drop_buffer_aps[2]++;
						aps[2].erase(aps[2].begin());
						
						if(delay_aps[2].size() > 0)
							{
							delay_aps[2].erase(delay_aps[2].begin());
							}	
						}

					aps[2].push_back(ap2);
					delay_aps[2].push_back(clock());
					energy_consumption_aps[2] = energy_consumption_aps[2] + (32 * 11) * (tx - idle);
					energy_consumption_aps[id2]= energy_consumption_aps[id2]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet_aps[id2]++;
					aps[id2][0].no_ctrans++;
					data_siz[id2] = aps[id2][0].data_size;

					if(aps[id2][0].no_ctrans > max_try)
						{
						packet_drop_aps[id2]++;
						aps[id2].erase(aps[id2].begin());
						
						if(delay_aps[id2].size() > 0)
							{
							delay_aps[id2].erase(delay_aps[id2].begin());
							}
						}
						
					waste_energy[id2]= waste_energy[id2]+ (31.25 * data_siz[id2] * (tx-sleepp));	
					}	
					
				energy_consumption[id2]= energy_consumption[id2]+ (31.25 * data_siz[id2] * (tx-sleepp)); 
				energy_consumption_aps[2] = energy_consumption_aps[2] + 31.25 * data_siz[id2] * (rx - idle);				
				ber_sensor0[id2] = ber_sensor0[id2] + data_siz[id2] * gber2 * 8;
				total_bit[id2] = total_bit[id2] + data_siz[id2] * 8;
				gts_ber2 = gts_ber2 + data_siz[id2] * gber2 * 8;
				gts_pcount2 = gts_pcount2 + data_siz[id2] * 8;
	
				while(clock()<(emg_t2+(31.25 * ap2.data_size)+ack_tr)){}	
				}
			else
				{
				waste_energy1[id2]= waste_energy1[id2]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_t2+2500){}
				}			
					
			if(!aps[id2].empty() && clock()<((gts_t2+slot_length) - 3500))
				{
				goto GP13;
				}
			}	
			
end_gts_p3:	while(clock() < (gts_t2 + slot_length)){}		
		}

	for(int i=5; i<7; i++)
		{
		energy_consumption_aps[i] = energy_consumption_aps[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[2] = energy_consumption_aps[2] + (7 * slot_length * idle);
	}	
	
void gts3()
	{
	for(int i=0; i<7; i++) //gts number start
		{
		gts_ct0 = clock();
		id3 = gts_id3[i];
		
		if(id3 == no_of_sensors)
			{
			blacklist0++;
			goto end_gts_c1;
			}

		if((i%4) == 0)
			{
			gber3 = ber0[id3][3];
			}
		else if((i%4) == 1)
			{
			gber3 = ber1[id3][3];
			}
		else if((i%4) == 2)
			{
			gber3 = ber2[id3][3];
			}
		else
			{
			gber3 = ber3[id3][3];
			}
			
		cui_ber[3] = cui_ber[3] + gber3;
		cui_gts[3]++;	

 		if(clock()<((gts_ct0+slot_length)-(tr[id3]+ack_tr)))
			{
GC11:			emg_ct0 = clock();
			
			if(!nodes[id3].empty())
				{
				if(gber3 <= 0.5 && gts_id0[i] != 1)
					{	
					clatency3 = clock() - delay_time[id3][0];
					
					if(0 <= id3 && id3 < (no_of_sensors/16) && gber3 <= 0.1 && clatency3 <= pl1[id3])
						{
						ap3.data_type = 0;
						ap3.data_check = 0;
						check000++;
						}
					else if((no_of_sensors/16)<= id3 && id3 < (no_of_sensors/8) && gber3 <= 0.3 && clatency3 <= pl1[id3])
						{
						ap3.data_type = 1;
						ap3.data_check = 1;
						check111++;
						}
					else if((no_of_sensors/8)<= id3 && id3 <(3*(no_of_sensors/16)) && gber3 <= 0.2 && clatency3 <= pl1[id3])
						{
						ap3.data_type = 2;
						ap3.data_check = 2;
						check222++;
						}
					else if((3*(no_of_sensors/16))<= id3 && id3 < (no_of_sensors/4) && gber3 <= 0.5 && clatency3 <= pl1[id3])
						{
						ap3.data_type = 3;
						ap3.data_check = 3;
						check333++;
						}
					else
						{
						if(0 <= id3 && id3 <(no_of_sensors/16))
							{
							ap3.data_type = 0;
							}
						else if((no_of_sensors/16)<= id3 && id3 <(no_of_sensors/8))
							{
							ap3.data_type = 1;
							}
						else if((no_of_sensors/8)<= id3 && id3 <(3*(no_of_sensors/8)))
							{
							ap3.data_type = 2;
							}
						else
							{
							ap3.data_type = 3;
							}
						
						ap3.data_check = 4;
						}	

					if(ap3.data_type == ap3.data_check)
						{test3++;
						packet_count1[id3]++;
						
						if(ap3.data_check == 0)
							{
							valid000++;
							}
						else if(ap3.data_check == 1)
							{
							valid111++;
							}
						else if(ap3.data_check == 2)
							{
							valid222++;
							}
						else			
							{
							valid333++;
							}
 						}
					else
						{
						invalid[id3]++;
						waste_energy[id3]= waste_energy[id3]+ (tr[id3] * (tx-sleepp));
						}

					latency1[id3]= latency1[id3] + (clock() - delay_time[id3][0]);	
					ap3.latency = clock() - delay_time[id3][0];
					ap3.data_size = ps[id3];
					ap3.plife0 = (nodes[id3][0].plife1) - clatency3;

					if(ap3.plife0 < 0)
						{
						checking++;
						}

					if(ap3.data_type == 0 || ap3.data_type == 1)
						{
						cd_count++;
						c_delay1[id3] = c_delay1[id3] + (clock() - delay_time[id3][0]);				
						}

					if(ap3.data_type == 0 || ap3.data_type == 2)
						{
						r_ber3 = r_ber3 + ps[id3] * gber3 * 8;
						r_count3 = r_count3 + ps[id3] * 8;	
						}

					nodes[id3].erase(nodes[id3].begin());
					
					if(delay_time[id3].size() > 0)
						{
						delay_time[id3].erase(delay_time[id3].begin());
						}

					if(aps[3].size() >= buffer_size)
						{
						packet_drop_buffer_aps[3]++;
						aps[3].erase(aps[3].begin());
						
						if(delay_aps[3].size() > 0)
							{
							delay_aps[3].erase(delay_aps[3].begin());
							}
						}

					aps[3].push_back(ap3);
					delay_aps[3].push_back(clock());
					energy_consumption_aps[3] = energy_consumption_aps[3] + (32 * 11) * (tx - idle);
					energy_consumption[id3]= energy_consumption[id3]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet[id3]++;
					nodes[id3][0].no_strans++;

					if(nodes[id3][0].no_strans > max_try)
						{
						packet_drop[id3]++;
						nodes[id3].erase(nodes[id3].begin());
						
						if(delay_time[id3].size() > 0)
							{
							delay_time[id3].erase(delay_time[id3].begin());
							}
						}
						
					waste_energy[id3]= waste_energy[id3]+ (tr[id3] * (tx-sleepp));	
					}
					
				energy_consumption[id3]= energy_consumption[id3]+ (tr[id3] * (tx-sleepp)); 
			        energy_consumption_aps[3] = energy_consumption_aps[3] + tr[id3] * (rx - idle);				
				ber_sensor1[id3] = ber_sensor1[id3] + ps[id3] * gber3 * 8;
				total_bit[id3] = total_bit[id3] + ps[id3] * 8;
				gts_ber3 = gts_ber3 + ps[id3] * gber3 * 8;
				gts_pcount3 = gts_pcount3 + ps[id3] * 8;

				while(clock()<emg_ct0+tr[id3]+ack_tr){}		
				}
			else
				{
				waste_energy1[id3]= waste_energy1[id3]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_ct0+2500){}
				}			
							
			if(!nodes[id3].empty() && clock()<((gts_ct0+slot_length) - (tr[id3]+ack_tr)))
				{
				goto GC11;
				}
			}	
		
		if((id3 % (no_of_sensors/4)) < ((3*no_of_sensors)/16))
			{
			gts_count0++;
			}
			
end_gts_c1:	while(clock()<(gts_ct0+slot_length)){}		
		}

	for(int i=0; i<(no_of_sensors/4); i++)
		{
		energy_consumption[i] = energy_consumption[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[3] = energy_consumption_aps[3] + (7 * slot_length * idle);
	}	
	
void gts4()
	{
	for(int i=0; i<7; i++) //gts number start
		{
		gts_ct1 = clock();
		id4 = gts_id4[i];
		
		if(id4 == no_of_sensors)
			{
			blacklist1++;
			goto end_gts_c2;
			}

		if((i%4) == 0)
			{
			gber4 = ber0[id4][4];
			}
		else if((i%4) == 1)
			{
			gber4 = ber1[id4][4];
			}
		else if((i%4) == 2)
			{
			gber4 = ber2[id4][4];
			}
		else
			{
			gber4 = ber3[id4][4];
			}
			
		cui_ber[4] = cui_ber[4] + gber4;
		cui_gts[4]++;	

 		if(clock()<((gts_ct1+slot_length)-(tr[id4]+ack_tr)))
			{
GC12:			emg_ct1 = clock();
			
			if(!nodes[id4].empty())
				{
				if(gber4 <= 0.5 && gts_id0[i] != 1)
					{	
					clatency4 = clock() - delay_time[id4][0];
					
					if((no_of_sensors/4)<= id4 && id4 <(5*(no_of_sensors/16)) && gber4 <= 0.1 && clatency4 <= pl1[id4])
						{
						ap4.data_type = 0;
						ap4.data_check = 0;
						check000++;
						}
					else if((5*(no_of_sensors/16))<= id4 && id4 <(3*(no_of_sensors/8)) && gber4 <= 0.3 && clatency4 <= pl1[id4])
						{
						ap4.data_type = 1;
						ap4.data_check = 1;
						check111++;
						}
					else if((3*(no_of_sensors/8))<= id4 && id4 <(7*(no_of_sensors/16)) && gber4 <= 0.2 && clatency4 <= pl1[id4])
						{
						ap4.data_type = 2;
						ap4.data_check = 2;
						check222++;
						}
					else if((7*(no_of_sensors/16))<= id4 && id4 <(no_of_sensors/2) && gber4 <= 0.5 && clatency4 <= pl1[id4])
						{
						ap4.data_type = 3;
						ap4.data_check = 3;
						check333++;
						}
					else
						{
						if((no_of_sensors/4)<= id4 && id4 <(5*(no_of_sensors/16)))
							{
							ap4.data_type = 0;
							}
						else if((5*(no_of_sensors/16))<= id4 && id4 <(3*(no_of_sensors/8)))
							{
							ap4.data_type = 1;
							}
						else if((3*(no_of_sensors/8))<= id4 && id4 <(7*(no_of_sensors/16)))
							{
							ap4.data_type = 2;
							}
						else
							{
							ap4.data_type = 3;
							}
						
						ap4.data_check = 4;
						}

					if(ap4.data_type == ap4.data_check)
						{test4++;
						packet_count1[id4]++;
						
						if(ap4.data_check == 0)
							{
							valid000++;
							}
						else if(ap4.data_check == 1)
							{
							valid111++;
							}
						else if(ap4.data_check == 2)
							{
							valid222++;
							}
						else			
							{
							valid333++;
							}
 						}
					else
						{
						invalid[id4]++;
						waste_energy[id4]= waste_energy[id4]+ (tr[id4] * (tx-sleepp));
						}

					latency1[id4]= latency1[id4] + (clock() - delay_time[id4][0]);	
					ap4.latency = clock() - delay_time[id4][0];
					ap4.data_size = ps[id4];
					ap4.plife0 = (nodes[id4][0].plife1) - clatency4;

					if(ap4.plife0 < 0)
						{
						checking++;
						}

					if(ap4.data_type == 0 || ap4.data_type == 1)
						{
						cd_count++;
						c_delay1[id4] = c_delay1[id4] + (clock() - delay_time[id4][0]);				
						}

					if(ap4.data_type == 0 || ap4.data_type == 2)
						{
						r_ber4 = r_ber4 + ps[id4] * gber4 * 8;
						r_count4 = r_count4 + ps[id4] * 8;	
						}

					nodes[id4].erase(nodes[id4].begin());
					
					if(delay_time[id4].size() > 0)
						{
						delay_time[id4].erase(delay_time[id4].begin());
						}

					if(aps[4].size() >= buffer_size)
						{
						packet_drop_buffer_aps[4]++;
						aps[4].erase(aps[4].begin());
						
						if(delay_aps[4].size() > 0)
							{
							delay_aps[4].erase(delay_aps[4].begin());
							}
						}

					aps[4].push_back(ap4);
					delay_aps[4].push_back(clock());
					energy_consumption_aps[4] = energy_consumption_aps[4] + (32 * 11) * (tx - idle);
					energy_consumption[id4]= energy_consumption[id4]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet[id4]++;
					nodes[id4][0].no_strans++;

					if(nodes[id4][0].no_strans > max_try)
						{
						packet_drop[id4]++;
						nodes[id4].erase(nodes[id4].begin());
						
						if(delay_time[id4].size() > 0)
							{
							delay_time[id4].erase(delay_time[id4].begin());
							}
						}
						
					waste_energy[id4]= waste_energy[id4]+ (tr[id4] * (tx-sleepp));	
					}
					
				energy_consumption[id4]= energy_consumption[id4]+ (tr[id4] * (tx-sleepp)); 
				energy_consumption_aps[4] = energy_consumption_aps[4] + tr[id4] * (rx - idle);				
				ber_sensor1[id4] = ber_sensor1[id4] + ps[id4] * gber4 * 8;
				total_bit[id4] = total_bit[id4] + ps[id4] * 8;
				gts_ber4 = gts_ber4 + ps[id4] * gber4 * 8;
				gts_pcount4 = gts_pcount4 + ps[id4] * 8;

				while(clock()<emg_ct1+tr[id4]+ack_tr){}		
				}
			else
				{
				waste_energy1[id4]= waste_energy1[id4]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_ct1+2500){}
				}			
							
			if(!nodes[id4].empty() && clock()<((gts_ct1+slot_length) - (tr[id4]+ack_tr)))
				{
				goto GC12;
				}
			}
			
		if((id4 % (no_of_sensors/4)) < ((3*no_of_sensors)/16))
			{
			gts_count1++;
			}	
			
end_gts_c2:	while(clock()<(gts_ct1+slot_length)){}		
		}

	for(int i=(no_of_sensors/4); i<(no_of_sensors/2); i++)
		{
		energy_consumption[i] = energy_consumption[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[4] = energy_consumption_aps[4] + (7 * slot_length * idle);
	}	
	
void gts5()
	{
	for(int i=0; i<7; i++) //gts number start
		{
		gts_ct2 = clock();
		id5 = gts_id5[i];
		
		if(id5 == no_of_sensors)
			{
			blacklist2++;
			goto end_gts_c3;
			}

		if((i%4) == 0)
			{
			gber5 = ber0[id5][5];
			}
		else if((i%4) == 1)
			{
			gber5 = ber1[id5][5];
			}
		else if((i%4) == 2)
			{
			gber5 = ber2[id5][5];
			}
		else
			{
			gber5 = ber3[id5][5];
			}
			
		cui_ber[5] = cui_ber[5] + gber5;
		cui_gts[5]++;	

 		if(clock()<((gts_ct2+slot_length)-(tr[id5]+ack_tr)))
			{
GC13:			emg_ct2 = clock();
			
			if(!nodes[id5].empty())
				{
				if(gber5 <= 0.5 && gts_id0[i] != 2)
					{	
					clatency5 = clock() - delay_time[id5][0];
					
					if((no_of_sensors/2)<= id5 && id5 <(9*(no_of_sensors/16)) && gber5 <= 0.1 && clatency5 <= pl1[id5])
						{
						ap5.data_type = 0;
						ap5.data_check = 0;
						check000++;
						}
					else if((9*(no_of_sensors/16))<= id5 && id5 <(5*(no_of_sensors/8)) && gber5 <= 0.3 && clatency5 <= pl1[id5])
						{
						ap5.data_type = 1;
						ap5.data_check = 1;
						check111++;
						}
					else if((5*(no_of_sensors/8))<= id5 && id5 <(11*(no_of_sensors/16)) && gber5 <= 0.2 && clatency5 <= pl1[id5])
						{
						ap5.data_type = 2;
						ap5.data_check = 2;
						check222++;
						}
					else if((11*(no_of_sensors/16))<= id5 && id5 <(3*(no_of_sensors/4)) && gber5 <= 0.5 && clatency5 <= pl1[id5])
						{
						ap5.data_type = 3;
						ap5.data_check = 3;
						check333++;
						}
					else
						{
						if((no_of_sensors/2)<= id5 && id5 <(9*(no_of_sensors/16)))
							{
							ap5.data_type = 0;
							}
						else if((9*(no_of_sensors/16))<= id5 && id5 <(5*(no_of_sensors/8)))
							{
							ap5.data_type = 1;
							}
						else if((5*(no_of_sensors/8))<= id5 && id5 <(11*(no_of_sensors/16)))
							{
							ap5.data_type = 2;
							}
						else
							{
							ap5.data_type = 3;
							}
						
						ap5.data_check = 4;
						}

					if(ap5.data_type == ap5.data_check)
						{test5++;
						packet_count1[id5]++;
						
						if(ap5.data_check == 0)
							{
							valid000++;
							}
						else if(ap5.data_check == 1)
							{
							valid111++;
							}
						else if(ap5.data_check == 2)
							{
							valid222++;
							}
						else			
							{
							valid333++;
							}
 						}
					else
						{
						invalid[id5]++;
						waste_energy[id5]= waste_energy[id5]+ (tr[id5] * (tx-sleepp));
						}

					latency1[id5]= latency1[id5] + (clock() - delay_time[id5][0]);	
					ap5.latency = clock() - delay_time[id5][0];
					ap5.data_size = ps[id5];
					ap5.plife0 = (nodes[id5][0].plife1) - clatency5;

					if(ap5.plife0 < 0)
						{
						checking++;
						}

					if(ap5.data_type == 0 || ap5.data_type == 1)
						{
						cd_count++;
						c_delay1[id5] = c_delay1[id5] + (clock() - delay_time[id5][0]);				
						}

					if(ap5.data_type == 0 || ap5.data_type == 2)
						{
						r_ber5 = r_ber5 + ps[id5] * gber5 * 8;
						r_count5 = r_count5 + ps[id5] * 8;	
						}

					nodes[id5].erase(nodes[id5].begin());
					
					if(delay_time[id5].size() > 0)
						{
						delay_time[id5].erase(delay_time[id5].begin());
						}

					if(aps[5].size() >= buffer_size)
						{
						packet_drop_buffer_aps[5]++;
						aps[5].erase(aps[5].begin());
						
						if(delay_aps[5].size() > 0)
							{
							delay_aps[5].erase(delay_aps[5].begin());
							}
						}

					aps[5].push_back(ap5);
					delay_aps[5].push_back(clock());
					energy_consumption_aps[5] = energy_consumption_aps[5] + (32 * 11) * (tx - idle);
					energy_consumption[id5]= energy_consumption[id5]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet[id5]++;
					nodes[id5][0].no_strans++;

					if(nodes[id5][0].no_strans > max_try)
						{
						packet_drop[id5]++;
						nodes[id5].erase(nodes[id5].begin());
						
						if(delay_time[id5].size() > 0)
							{
							delay_time[id5].erase(delay_time[id5].begin());
							}
						}
						
					waste_energy[id5]= waste_energy[id5]+ (tr[id5] * (tx-sleepp));	
					}
					
				energy_consumption[id5]= energy_consumption[id5]+ (tr[id5] * (tx-sleepp)); 
				energy_consumption_aps[5] = energy_consumption_aps[5] + tr[id5] * (rx - idle);				
				ber_sensor1[id5] = ber_sensor1[id5] + ps[id5] * gber5 * 8;
				total_bit[id5] = total_bit[id5] + ps[id5] * 8;
				gts_ber5 = gts_ber5 + ps[id5] * gber5 * 8;
				gts_pcount5 = gts_pcount5 + ps[id5] * 8;

				while(clock()<emg_ct2+tr[id5]+ack_tr){}		
				}
			else
				{
				waste_energy1[id5]= waste_energy1[id5]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_ct2+2500){}
				}		
					
			if(!nodes[id5].empty() && clock()<((gts_ct2+slot_length) - (tr[id5]+ack_tr)))
				{
				goto GC13;
				}
			}
			
		if((id5 % (no_of_sensors/4)) < ((3*no_of_sensors)/16))
			{
			gts_count2++;
			}		
			
end_gts_c3:	while(clock()<(gts_ct2+slot_length)){}		
		}

	for(int i=(no_of_sensors/2); i<(3*(no_of_sensors/4)); i++)
		{
		energy_consumption[i] = energy_consumption[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[5] = energy_consumption_aps[5] + (7 * slot_length * idle);
	}
	
void gts6()
	{
	for(int i=0; i<7; i++) //gts number start
		{
		gts_ct3 = clock();
		id6 = gts_id6[i];
		
		if(id6 == no_of_sensors)
			{
			blacklist3++;
			goto end_gts_c4;
			}

		if((i%4) == 0)
			{
			gber6 = ber0[id6][6];
			}
		else if((i%4) == 1)
			{
			gber6 = ber1[id6][6];
			}
		else if((i%4) == 2)
			{
			gber6 = ber2[id6][6];
			}
		else
			{
			gber6 = ber3[id6][6];
			}
			
		cui_ber[6] = cui_ber[6] + gber6;
		cui_gts[6]++;

 		if(clock()<((gts_ct3+slot_length)-(tr[id6]+ack_tr)))
			{
GC14:			emg_ct3 = clock();
			
			if(!nodes[id6].empty())
				{
				if(gber6 <= 0.5 && gts_id0[i] != 2)
					{	
					clatency6 = clock() - delay_time[id6][0];
					
					if((3*(no_of_sensors/4))<= id6 && id6 <(13*(no_of_sensors/16)) && gber6 <= 0.1 && clatency6 <= pl1[id6])
						{
						ap6.data_type = 0;
						ap6.data_check = 0;
						check000++;
						}
					else if((13*(no_of_sensors/16))<= id6 && id6 <(7*(no_of_sensors/8)) && gber6 <= 0.3 && clatency6 <= pl1[id6])
						{
						ap6.data_type = 1;
						ap6.data_check = 1;
						check111++;
						}
					else if((7*(no_of_sensors/8))<= id6 && id6 <(15*(no_of_sensors/16)) && gber6 <= 0.2 && clatency6 <= pl1[id6])
						{
						ap6.data_type = 2;
						ap6.data_check = 2;
						check222++;
						}
					else if((15*(no_of_sensors/16))<= id6 && id6 < no_of_sensors && gber6 <= 0.5 && clatency6 <= pl1[id6])
						{
						ap6.data_type = 3;
						ap6.data_check = 3;
						check333++;
						}
					else
						{
						if((3*(no_of_sensors/4))<= id6 && id6 <(13*(no_of_sensors/16)))
							{
							ap6.data_type = 0;
							}
						else if((13*(no_of_sensors/16))<= id6 && id6 <(7*(no_of_sensors/8)))
							{
							ap6.data_type = 1;
							}
						else if((7*(no_of_sensors/8))<= id6 && id6 <(15*(no_of_sensors/16)))
							{
							ap6.data_type = 2;
							}
						else
							{
							ap6.data_type = 3;
							}
						
						ap6.data_check = 4;
						}

					if(ap6.data_type == ap6.data_check)
						{test6++;
						packet_count1[id6]++;
						
						if(ap6.data_check == 0)
							{
							valid000++;
							}
						else if(ap6.data_check == 1)
							{
							valid111++;
							}
						else if(ap6.data_check == 2)
							{
							valid222++;
							}
						else			
							{
							valid333++;
							}
 						}
					else
						{
						invalid[id6]++;
						waste_energy[id6]= waste_energy[id6]+ (tr[id6] * (tx-sleepp));
						}

					latency1[id6]= latency1[id6] + (clock() - delay_time[id6][0]); 	
					ap6.latency = clock() - delay_time[id6][0];
					ap6.data_size = ps[id6];
					ap6.plife0 = (nodes[id6][0].plife1) - clatency6;

					if(ap6.plife0 < 0)
						{
						checking++;
						}

					if(ap6.data_type == 0 || ap6.data_type == 1)
						{
						cd_count++;
						c_delay1[id6] = c_delay1[id6] + (clock() - delay_time[id6][0]);				
						}

					if(ap6.data_type == 0 || ap6.data_type == 2)
						{
						r_ber6 = r_ber6 + ps[id6] * gber6 * 8;
						r_count6 = r_count6 + ps[id6] * 8;	
						}

					nodes[id6].erase(nodes[id6].begin());
					
					if(delay_time[id6].size() > 0)
						{
						delay_time[id6].erase(delay_time[id6].begin());
						}

					if(aps[6].size() >= buffer_size)
						{
						packet_drop_buffer_aps[6]++;
						aps[6].erase(aps[6].begin());
						
						if(delay_aps[6].size() > 0)
							{
							delay_aps[6].erase(delay_aps[6].begin());
							}
						}

					aps[6].push_back(ap6);
					delay_aps[6].push_back(clock());
					energy_consumption_aps[6] = energy_consumption_aps[6] + (32 * 11) * (tx - idle);
					energy_consumption[id6]= energy_consumption[id6]+ ((32 * 11) * (rx - sleepp));
					}
				else
					{
					fail_packet[id6]++;
					nodes[id6][0].no_strans++;

					if(nodes[id6][0].no_strans > max_try)
						{
						packet_drop[id6]++;
						nodes[id6].erase(nodes[id6].begin());
						
						if(delay_time[id6].size() > 0)
							{
							delay_time[id6].erase(delay_time[id6].begin());
							}
						}
						
					waste_energy[id6]= waste_energy[id6]+ (tr[id6] * (tx-sleepp));	
					}
					
				energy_consumption[id6]= energy_consumption[id6]+ (tr[id6] * (tx-sleepp)); 
				energy_consumption_aps[6] = energy_consumption_aps[6] + tr[id6] * (rx - idle);				
				ber_sensor1[id6] = ber_sensor1[id6] + ps[id6] * gber6 * 8;
				total_bit[id6] = total_bit[id6] + ps[id6] * 8;
				gts_ber6 = gts_ber6 + ps[id6] * gber6 * 8;
				gts_pcount6 = gts_pcount6 + ps[id6] * 8;

				while(clock()<emg_ct3+tr[id6]+ack_tr){}		
				}
			else
				{
				waste_energy1[id6]= waste_energy1[id6]+ (2500 * (idle-sleepp));
				
				while(clock()<emg_ct3+2500){}
				}
									
			if(!nodes[id6].empty() && clock()<((gts_ct3+slot_length) - (tr[id6]+ack_tr)))
				{
				goto GC14;
				}
			}
			
		if((id6 % (no_of_sensors/4)) < ((3*no_of_sensors)/16))
			{
			gts_count3++;
			}		
			
end_gts_c4:	while(clock()<(gts_ct3+slot_length)){}		
		}

	for(int i=(3 * (no_of_sensors/4)); i<no_of_sensors; i++)
		{
		energy_consumption[i] = energy_consumption[i] +  (7 * slot_length * sleepp);
		}
		
	energy_consumption_aps[6] = energy_consumption_aps[6] + (7 * slot_length * idle);
	}												

void sf0()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf0_count++;
		cout<<"Superframe number 0 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;
		superframe_start0 = clock();
		
		beacon0[0] = clock();
		beacon0[1] = beacon0[0] + 9 * slot_length;
		beacon0[2] = beacon0[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here0;
			}

		if(superframe_number % 4 == 0)
			{
			msf_number++;
			}

		cout<<"MSF number "<<msf_number<<endl;

		while(clock() - superframe_start0 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon0[0] && beacon0[1] > clock())
				{
				cout<<"CAP running0"<<endl;
//CAP start		
				csmaca0();	
//CAP end				
				while(beacon0[1] > clock()){}
				}
			if(clock() >= beacon0[1] && beacon0[2] > clock())
				{
				cout<<"CFP running0"<<endl;
//CFP start
				gts0();
//CFP end				
				while(beacon0[2] > clock()){}
				}			
			}
	
		sbound[0]++;

here0:		while(clock() < beacon0[2]){}
				
		superframe_number++;
		
		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out0;
			}
		}
		
out0: 	cout<<"sf 0 out"<<endl;	
	}
	
void sf1()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf1_count++;
		cout<<"Superframe number 1 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon1[0] = clock();
		beacon1[1] = beacon1[0] + 9 * slot_length;
		beacon1[2] = beacon1[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here1;
			}
		
		superframe_start1 = clock();

		while(clock() - superframe_start1 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon1[0] && beacon1[1] > clock())
				{
				cout<<"CAP running1"<<endl;
//CAP start		
				csmaca1();	
//CAP end				
				while(beacon1[1] > clock()){}
				}
			if(clock() >= beacon1[1] && beacon1[2] > clock())
				{
				cout<<"CFP running1"<<endl;
//CFP start
				gts1();
//CFP end				
				while(beacon1[2] > clock()){}
				}			
			}
	
		sbound[1]++;
		
here1:		while(clock() < beacon1[2]){}

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out1;
			}
		}
		
out1: 	cout<<"sf 1 out"<<endl;		
	}	
	
void sf2()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf2_count++;
		cout<<"Superframe number 2 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon2[0] = clock();
		beacon2[1] = beacon2[0] + 9 * slot_length;
		beacon2[2] = beacon2[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here2;
			}
		
		superframe_start2 = clock();

		while(clock() - superframe_start2 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon2[0] && beacon2[1] > clock())
				{
				cout<<"CAP running2"<<endl;
//CAP start		
				csmaca2();	
//CAP end				
				while(beacon2[1] > clock()){}
				}
			if(clock() >= beacon2[1] && beacon2[2] > clock())
				{
				cout<<"CFP running2"<<endl;
//CFP start
				gts2();
//CFP end				
				while(beacon2[2] > clock()){}
				}			
			}
	
		sbound[2]++;

here2:		while(clock() < beacon2[2]){}	

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out2;
			}		
		}
		
out2:	cout<<"sf 2 out"<<endl;		
	}
	
void sf3()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf3_count++;
		cout<<"Superframe number 3 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon3[0] = clock();
		beacon3[1] = beacon3[0] + 9 * slot_length;
		beacon3[2] = beacon3[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here3;
			}
		
		superframe_start3 = clock();

		while(clock() - superframe_start3 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon3[0] && beacon3[1] > clock())
				{
				cout<<"CAP running3"<<endl;
//CAP start		
				csmaca3();	
//CAP end				
				while(beacon3[1] > clock()){}
				}
			if(clock() >= beacon3[1] && beacon3[2] > clock())
				{
				cout<<"CFP running3"<<endl;
//CFP start
				gts3();
//CFP end				
				while(beacon3[2] > clock()){}
				}			
			}
	
		sbound[3]++;

here3:		while(clock() < beacon3[2]){}	

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out3;
			}		
		}
		
out3:	cout<<"sf 3 out"<<endl;		
	}

void sf4()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf4_count++;
		cout<<"Superframe number 4 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon4[0] = clock();
		beacon4[1] = beacon4[0] + 9 * slot_length;
		beacon4[2] = beacon4[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here4;
			}
		
		superframe_start4 = clock();

		while(clock() - superframe_start4 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon4[0] && beacon4[1] > clock())
				{
				cout<<"CAP running4"<<endl;
//CAP start		
				csmaca4();	
//CAP end				
				while(beacon4[1] > clock()){}
				}
			if(clock() >= beacon4[1] && beacon4[2] > clock())
				{
				cout<<"CFP running4"<<endl;
//CFP start
				gts4();
//CFP end				
				while(beacon4[2] > clock()){}
				}			
			}
	
		sbound[4]++;

here4:		while(clock() < beacon4[2]){}	

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out4;
			}		
		}
		
out4:	cout<<"sf 4 out"<<endl;		
	}	

void sf5()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf5_count++;
		cout<<"Superframe number 5 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon5[0] = clock();
		beacon5[1] = beacon5[0] + 9 * slot_length;
		beacon5[2] = beacon5[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here5;
			}
		
		superframe_start5 = clock();

		while(clock() - superframe_start5 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon5[0] && beacon5[1] > clock())
				{
				cout<<"CAP running5"<<endl;
//CAP start		
				csmaca5();	
//CAP end				
				while(beacon5[1] > clock()){}
				}
			if(clock() >= beacon5[1] && beacon5[2] > clock())
				{
				cout<<"CFP running5"<<endl;
//CFP start
				gts5();
//CFP end				
				while(beacon5[2] > clock()){}
				}			
			}
	
		sbound[5]++;

here5:		while(clock() < beacon5[2]){}	

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out5;
			}		
		}
		
out5:	cout<<"sf 5 out"<<endl;		
	}	

void sf6()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))//simulation boundary
		{sf6_count++;
		cout<<"Superframe number 6 = "<<superframe_number<<endl;
		cout<<"Clock = "<<clock()<<endl;

		beacon6[0] = clock();
		beacon6[1] = beacon6[0] + 9 * slot_length;
		beacon6[2] = beacon6[1] + 7 * slot_length;		

		if(superframe_number == -1)
			{
			goto here6;
			}
		
		superframe_start6 = clock();

		while(clock() - superframe_start6 < sf_length * slot_length)//superframe boundary
			{
			if(clock() >= beacon6[0] && beacon6[1] > clock())
				{
				cout<<"CAP running6"<<endl;
//CAP start		
				csmaca6();	
//CAP end				
				while(beacon6[1] > clock()){}
				}
			if(clock() >= beacon6[1] && beacon6[2] > clock())
				{
				cout<<"CFP running6"<<endl;
//CFP start
				gts6();
//CFP end				
				while(beacon6[2] > clock()){}
				}			
			}
	
		sbound[6]++;

here6:		while(clock() < beacon6[2]){}	

		if((clock() - start) > (sim_time * (double)CLOCKS_PER_SEC))
			{
			goto out6;
			}		
		}
		
out6:	cout<<"sf 6 out"<<endl;		
	}		

void packet_generation(int node_number, double pgr)
	{
	if(nodes[node_number].size() < bs[node_number])
		{
		node.data_gen_rate = pgr;
		node.plife1 = pl1[node_number]; 
		nodes[node_number].push_back(node);
		delay_time[node_number].push_back(clock());
		}
	else
		{
		packet_drop_buffer[node_number]++;
		nodes[node_number].erase(nodes[node_number].begin());
		delay_time[node_number].erase(delay_time[node_number].begin());

		node.data_gen_rate = pgr;
		node.plife1 = pl1[node_number]; 
		nodes[node_number].push_back(node);
		delay_time[node_number].push_back(clock());
		}
	}

void ran_pac_gen(vector<int> pgr)
	{
	vector<int> n(no_of_sensors);

	for(int i=0; i<no_of_sensors; i++)
		{
		n[i] = 1;
		}	 

	for(int n0=1; n0<= sim_time*10;)
		{
		if(clock()/10000 > n0*10)
			{
   			n0++;
			}

		for(int i=0; i<no_of_sensors; i++)
			{
			if(clock()/10000 > ceil(n[i]*(100/(double)pgr[i])))
				{
				packet_generation(i, (double)pgr[i]);
				n[i]++;
				packet_gen[i]++;
				}
			}
		}	

// for total energy and waste energy per bit transmission calculation
	double total_energy = 0.0;
	double total_waste = 0.0;
	double total_invalid = 0.0;
	double total_valid = 0.0;
	double total_failed = 0.0;
	
	for(int i=0; i<no_of_aps+no_of_sensors; i++)
		{
		total_invalid = total_invalid + invalid[i];
		}
	
	for(int i=0; i<no_of_aps+no_of_sensors; i++)
		{
		if(i<no_of_sensors)
			{
			total_failed = total_failed + fail_packet_aps[i] + req_fail_packet_aps[i];
			}
		else
			{
			total_failed = total_failed + fail_packet[i] + req_fail_packet[i];
			}	
		}
	
	total_energy = total_energy + co_energy_consumption;

	for(int i=0; i<no_of_aps; i++)
		{
		total_energy = total_energy + energy_consumption_aps[i];
		}	
		
	for(int i=0; i<no_of_sensors; i++)
		{
		total_energy = total_energy + energy_consumption[i];
		}
		
	for(int i=0; i<(no_of_aps + no_of_sensors); i++)
		{
		total_waste = total_waste + waste_energy[i];
		}	

	//PM6 (Total Energy Consumption)
	cout<<"Total energy consumption (J) = "<<(double) total_energy<<endl;

	//PM6 (Wasted Energy per Bit Transmission)
	cout<<"WE per Trans. = "<<(double) total_waste/(double) (total_failed + total_invalid)<<endl;	
		
// for average constrained delay calculations (micro-sec)
	double total_latency = 0.0;
	double acd; 
	
	for(int i=0; i<no_of_aps; i++)
		{
		total_latency = total_latency + c_delay0[i];
		}
		
	for(int i=0; i<no_of_sensors; i++)
		{
		total_latency = total_latency + c_delay1[i];
		}		
	
	acd = (double) total_latency/ (double) cd_count;
	//PM5 (Average Delay)
	cout<<"Avg. const. delay = "<< acd <<endl;

// for throughput per superframe calculation (kbps)
	double total_bits = 0.0;

	for(int i=0; i<(no_of_aps + no_of_sensors); i++)
		{
		total_bits = total_bits + total_bit[i];
		}
	//PM4
	cout<<"TP per superframe = "<< ((total_bits/sim_time) / (1024 * 7)) <<" Kbps"<<endl;

// for GUI calculations	
	double GUI;
	
	GUI = (double) ((gts_count0 + gts_count1 + gts_count2 + gts_count3)/ (superframe_number * 28));
	//PM3 (GTS Utilization Index)
	cout<<"GUI (blacklist not considered) = "<<(double) GUI<<endl;

	int blacklist;
	blacklist = blacklist0+blacklist1+blacklist2+blacklist3;

	GUI = (double) ((gts_count0 + gts_count1 + gts_count2 + gts_count3)/ ((superframe_number * 28)-blacklist));
	//PM3 (GTS Utilization Index)
	cout<<"GUI (blacklist considered) = "<<(double) GUI<<endl;

// for CUI calculations	
	double CUI;
	double gts_b0 = cui_ber[0] + cui_ber[1] + cui_ber[2] + cui_ber[3] + cui_ber[4] + cui_ber[5] + cui_ber[6];
	int gts_b1 = cui_gts[0] + cui_gts[1] + cui_gts[2] + cui_gts[3] + cui_gts[4] + cui_gts[5] + cui_gts[6];
	
	CUI = (double) (gts_b0/gts_b1);
	//PM2 (Channel Utilization Index)
	cout<<"CUI (main)= "<<(double) CUI<<endl;

	double r_b0 = r_ber0 + r_ber1 + r_ber2 + r_ber3 + r_ber4 + r_ber5 + r_ber6;
	double r_b1 = r_count0 + r_count1 + r_count2 + r_count3 + r_count4 + r_count5 + r_count6;
	
	CUI = (double) (r_b0/r_b1);
	//PM2 (Channel Utilization Index)
	cout<<"CUI (only reliability considered)= "<<(double) CUI<<endl;
	
// for reachability calculations
	//PM1 L-0 
	cout<<"valid0 "<<valid0<<endl;
	cout<<"valid1 "<<valid1<<endl;
	cout<<"valid2 "<<valid2<<endl;
	cout<<"valid3 "<<valid3<<endl;

	//PM1 L-1
	cout<<"valid00 "<<valid00<<endl;
	cout<<"valid11 "<<valid11<<endl;
	cout<<"valid22 "<<valid22<<endl;
	cout<<"valid33 "<<valid33<<endl;

	//PM1 L-2
	cout<<"valid000 "<<valid000<<endl;
	cout<<"valid111 "<<valid111<<endl;
	cout<<"valid222 "<<valid222<<endl;
	cout<<"valid333 "<<valid333<<endl;

// no of superframes calculations
	cout<<"sf 0 count = "<<sf0_count<<endl;
	cout<<"sf 1 count = "<<sf1_count<<endl;
	cout<<"sf 2 count = "<<sf2_count<<endl;
	cout<<"sf 3 count = "<<sf3_count<<endl;
	cout<<"sf 4 count = "<<sf4_count<<endl;
	cout<<"sf 5 count = "<<sf5_count<<endl;
	cout<<"sf 6 count = "<<sf6_count<<endl;
 
 cout<<"check set = "<<check_set<<endl;
	}

void set_ber()
	{
	while((clock() - start) <= (sim_time * (double)CLOCKS_PER_SEC))
		{
		ber_time = clock();

		channel0();
		channel1();
		channel2();
		channel3();
		
		for(int i=0; i<7; i++)
			{
			gts_id0[i] = 0;
			gts_id1[i] = 0;
			gts_id2[i] = 0;
			gts_id3[i] = no_of_sensors;
			gts_id4[i] = no_of_sensors;
			gts_id5[i] = no_of_sensors;
			gts_id6[i] = no_of_sensors;
			}
			
		for(int i=0; i<no_of_aps; i++)
			{
			request0[i] = 0;
			}	
			
		for(int i=0; i<no_of_sensors; i++)
			{
			request1[i] = 0;
			}	
		
		first_done++;
	
		while(clock() < (ber_time + (16 * 16 * slot_length))){}
		}
	}

int main()
	{// update the rading part
	superframe_number = -1;
	msf_number = -1;
	start = clock();

	for(int i=0; i<no_of_sensors; i++)
		{	
		packet_gen[i] = 0;
		}

	for(int i=0; i<no_of_aps; i++)
		{	
		packet_count0[i] = 0;
		}

	for(int i=0; i<no_of_sensors; i++)
		{	
		packet_count1[i] = 0;
		}

	for(int i=0; i<7; i++)
		{
		sbound[i] = 0;	//superframe count for each sf
		}
	
	ofstream pgrf;	//pgr
	pgrf.open("pgr.csv");
	
	for(int i=0; i<no_of_sensors; i++)
		{
		pgr[i] = random_pgr(20);
		pgrf<<pgr[i]<<"\t";
		}
		
	pgrf.close();

	ofstream bsf;	//bs
	bsf.open("bs.csv");
	
	for(int i=0; i<no_of_sensors; i++)
		{
		bs[i] = random_bs(50);
		bsf<<bs[i]<<"\t";
		}
		
	bsf.close();
	
	ofstream psf;	//ps
	psf.open("ps.csv");
	
	for(int i=0; i<no_of_sensors; i++)
		{
		ps[i] = random_ps(100);
		psf<<ps[i]<<"\t";
		}
		
	psf.close();

	ofstream pl0f;	//pl0
	pl0f.open("pl0.csv");
	
	for(int i=0; i<no_of_aps; i++)
		{
		pl0[i] = random_pl(200000, 2000000);
		pl0f<<pl0[i]<<"\t";
		}
		
	pl0f.close();

	ofstream pl1f;	//pl
	pl1f.open("pl1.csv");
	
	for(int i=0; i<no_of_sensors; i++)
		{
		if(i%x < (x/4))
			{
			pl1[i] = random_pl(200000, 350000);
			}
		else if(i%x >= (x/4) && i%x < (x/2))
			{
			pl1[i] = random_pl(350000, 500000);
			}
		else if(i%x >= (x/2) && i%x < (3*(x/4)))
			{
			pl1[i] = random_pl(500000, 750000);
			}
		else
			{
			pl1[i] = random_pl(750000, 1000000);
			}		
	
		pl1f<<pl1[i]<<"\t";
		}
		
	pl1f.close();

	for(int i = 0; i<no_of_sensors; i++)
		{
		tr[i] = (double) (31.25 * ps[i]);
		}

	omp_set_num_threads(9);
	
        #pragma omp parallel
		{
		#pragma omp for
		for(int i=0; i<9; i++)
			{ 
        	        if(i==0)
				{
				ran_pac_gen(pgr);
				}
			if(i==1)
				{
				set_ber();	
				}         
			if(i==2)
				{
				sf0();	
				}
			if(i==3)
				{
				sf1();
				}
			if(i==4)
				{
				sf2();
				}
			if(i==5)
				{
				sf3();
				}
			if(i==6)
				{
				sf4();
				}
			if(i==7)
				{
				sf5();
				}
			if(i==8)
				{
				sf6();
				}		
        	  	}

		if(omp_get_thread_num() > 1)
			{
			#pragma omp barrier
			}
		}

	cout<<"finally out"<<endl;
	return 0;
	}
