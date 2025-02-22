#ifndef IEEE
#define IEEE
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <omp.h>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;
using namespace boost;

struct node_parameters
	{
	int data_gen_rate;
	int no_strans = 0;
	double plife1;	                     
        };     
        
struct ap_parameters
	{
	int data_type;
	int data_check;
	double latency;
	int data_size;
	int no_ctrans = 0;
	double plife0;	                     
        };                       

node_parameters node;
ap_parameters ap0, ap1, ap2, ap3, ap4, ap5, ap6;
double sim_time = 120; // second
double slot_length = 15360; // microsecond
double cap_so = 138240; // microsecond
double sf_length = 16;
double no_of_aps = 7;
int no_of_sensors = 16;
double no_of_channels = 4;
double sleepp = .00000000004; // joule per micro sec
double idle = .00000000067; // joule per micro sec
double tx = .00000002923; // joule per micro sec
double rx = .00000003505; // joule per micro sec
double initial_energy = 0.05; // joule
int max_try = 7; // max re-try for same packet
vector<vector<double> > fber((15 * (no_of_aps + no_of_sensors)), vector<double> (no_of_channels));
vector<vector<double> > ber((no_of_aps + no_of_sensors), vector<double> (no_of_channels)); // for access point and coordinator ber
vector<double> ber_sensor0(no_of_aps), ber_sensor1(no_of_sensors);
double mintime0, mintime1, mintime2, mintime3, mintime4, mintime5, mintime6;
double sensor_mintime0, sensor_mintime1, sensor_mintime2, sensor_mintime3, sensor_mintime4, sensor_mintime5, sensor_mintime6;
double t0, t1, t2, ct0, ct1, ct2, ct3; // to keep track of transmission in cap
int beacon_size = 50; // byte
int buffer_size = 30; //coordinator buffer size
vector<double> tr(no_of_sensors); // time required to transmit 60 bytes data in micro-second
double ack_tr = 352; // time required to transmit 11 bytes ACK in micro-second
vector<double> energy_consumption(no_of_sensors), energy_consumption_aps(no_of_aps);
double co_energy_consumption = 0.0;
vector<vector<node_parameters> >nodes(no_of_sensors);
vector<vector<ap_parameters> >aps(no_of_aps);  
double temp_t0, temp_t1, temp_t2, temp_c0, temp_c1, temp_c2, temp_c3; // start time of each superframe 
vector<int> request0(6), request1(no_of_sensors);
double gts_t0, gts_t1, gts_t2, gts_ct0, gts_ct1, gts_ct2, gts_ct3; // start time of each gts slot
double emg_t0, emg_t1, emg_t2, emg_ct0, emg_ct1, emg_ct2, emg_ct3; // to keep track of transmission in gts
vector<int> gts_id0(7), gts_id1(7), gts_id2(7), gts_id3(7), gts_id4(7), gts_id5(7), gts_id6(7); // to keep track of the gts allocated devices with how many gts allocated
int id0, id1, id2, id3, id4, id5, id6;
vector<double> beacon0(3), beacon1(3), beacon2(3), beacon3(3), beacon4(3), beacon5(3), beacon6(3);
int superframe_number, msf_number;
clock_t start;
vector<int> sbound(7); // superframe boundary
double pit0, pit1, pit2, pit3, pit4, pit5, pit6;
vector<int> check_empty0, check_empty1, check_empty2, check_empty3, check_empty4, check_empty5, check_empty6;
vector<int> macmaxbe0(no_of_aps), macminbe0(no_of_aps), be0(no_of_aps), nb0(no_of_aps), nbf0(no_of_aps);
vector<int> macmaxbe1(no_of_sensors), macminbe1(no_of_sensors), be1(no_of_sensors), nb1(no_of_sensors), nbf1(no_of_sensors);
vector<double> wait0(2), wait1(2), wait2(2), wait3(no_of_sensors/4), wait4(no_of_sensors/4), wait5(no_of_sensors/4), wait6(no_of_sensors/4); // to keep track of back-off time
vector<double> wt1(no_of_sensors/4), wt2(no_of_sensors/4), wt3(no_of_sensors/4), wt4(no_of_sensors/4); // to keep track of back-off time 
vector<vector<double> > delay_aps(no_of_aps), delay_time(no_of_sensors);
vector<int> packet_gen(no_of_sensors); // for keeping track of the number of generated packets
vector<int> packet_drop_buffer(no_of_sensors);
vector<int> packet_drop_buffer_aps(no_of_aps);
vector<int> packet_drop_aps(no_of_aps);
vector<int> packet_drop(no_of_sensors);
vector<double> latency0(no_of_aps), latency1(no_of_sensors);
vector<int> fail_packet(no_of_sensors), fail_packet_aps(no_of_aps); // failed packet count sensor wise due to high ber
vector<int> req_packet(no_of_sensors), req_packet_aps(no_of_aps);
vector<int> req_fail_packet(no_of_sensors), req_fail_packet_aps(no_of_aps);
vector<int> packet_count0(no_of_aps), packet_count1(no_of_sensors); // successful packet count sensor wise
vector<int>::iterator it0, it1, it2, it3, it4, it5, it6;
vector<int> lok(no_of_aps); // locks to check if tx will be successful
vector<int> ber_sf(16);
double superframe_start, superframe_start0,superframe_start1, superframe_start2, superframe_start3, superframe_start4, superframe_start5, superframe_start6;
vector<int> pgr(no_of_sensors), ps(no_of_sensors), bs(no_of_sensors), pl0(no_of_aps), pl1(no_of_sensors);
char comma;
vector<double> nwl0(no_of_sensors/4), nwl1(no_of_sensors/4), nwl2(no_of_sensors/4), nwl3(no_of_sensors/4);
vector<vector<double> >ber0((no_of_aps + no_of_sensors), vector<double> (no_of_aps + no_of_sensors)), ber1((no_of_aps + no_of_sensors), vector<double> (no_of_aps + no_of_sensors)), ber2((no_of_aps + no_of_sensors), vector<double> (no_of_aps + no_of_sensors)), ber3((no_of_aps + no_of_sensors), vector<double> (no_of_aps + no_of_sensors));
vector<int> invalid(no_of_aps+no_of_sensors);
double gts_count0=0.0, gts_count1=0.0, gts_count2=0.0, gts_count3=0.0;
double gts_ber0=0.0, gts_ber1=0.0, gts_ber2=0.0, gts_ber3=0.0, gts_ber4=0.0, gts_ber5=0.0, gts_ber6=0.0, gts_pcount0=0.0, gts_pcount1=0.0, gts_pcount2=0.0, gts_pcount3=0.0, gts_pcount4=0.0, gts_pcount5=0.0, gts_pcount6=0.0; 
double gber0, gber1, gber2, gber3, gber4, gber5, gber6;
vector<double> new_row0, new_row1, new_row2, new_row3, new_row4, new_row5, new_row6;
double rand_b0, rand_b1, rand_b2, rand_b3;
double start_time, ber_time;
int check_type = 0, data_energy0, data_energy1, data_energy2; //delete
double clatency0, clatency1, clatency2, clatency3, clatency4, clatency5, clatency6;
int check0=0, check1=0, check2=0, check3=0;
int check00=0, check11=0, check22=0, check33=0;
int check000=0, check111=0, check222=0, check333=0;
int valid0=0, valid1=0, valid2=0, valid3=0;
int valid00=0, valid11=0, valid22=0, valid33=0;
int valid000=0, valid111=0, valid222=0, valid333=0;
vector<double> total_bit(no_of_aps + no_of_sensors);
vector<double> data_siz(no_of_aps);
vector<double> waste_energy(no_of_aps + no_of_sensors), waste_energy1(no_of_aps + no_of_sensors);
int checking = 0, first_done = 0;
int test0 = 0, test1 = 0, test2 = 0, test3 = 0, test4 = 0, test5 = 0, test6 = 0;
int sf0_count=0, sf1_count=0, sf2_count=0, sf3_count=0, sf4_count=0, sf5_count=0, sf6_count=0;
int blacklist0=0, blacklist1=0, blacklist2=0, blacklist3=0;
double r_ber0=0.0, r_ber1=0.0, r_ber2=0.0, r_ber3=0.0, r_ber4=0.0, r_ber5=0.0, r_ber6=0.0, r_count0=0.0, r_count1=0.0, r_count2=0.0, r_count3=0.0, r_count4=0.0, r_count5=0.0, r_count6=0.0; 
vector<double> c_delay0(no_of_aps), c_delay1(no_of_sensors);
int cd_count=0;
int check_set = 0;
int x = no_of_sensors/4;
vector<double> cui_ber(no_of_aps);
vector<double> cui_gts(no_of_aps);

#endif
