// Automatically generated C++ file on Thu Oct 24 18:58:38 2024
//
// To build with Digital Mars C++ Compiler: 
//
//    dmc -mn -WD digitalfilter_x1.cpp kernel32.lib
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RATIO_OVERSAMPLING 8
#define SIZE_USB_BUFFER 300000
#define SIZE_OUTPUT_BUFFER 300000
#define OVERSAMPLING_TIMING_PRESCALE 1

typedef struct
{
   double debug[8];
}DEBUG_INNER_FUNC;

const double fir_filter_coef_8x[] =
{3.28689029e-09,4.62867609e-09,4.44081220e-09,1.41808699e-09
,-5.45893585e-09,-1.63857620e-08,-3.02170690e-08,-4.41472886e-08
,-5.37722144e-08,-5.36704304e-08,-3.85424075e-08,-4.79838043e-09
,4.76801155e-08,1.14026409e-07,1.83624336e-07,2.40567906e-07
,2.65658969e-07,2.39964381e-07,1.49565363e-07,-9.28338958e-09
,-2.25712979e-07,-4.71817378e-07,-7.03454138e-07,-8.65065549e-07
,-8.98604470e-07,-7.55719627e-07,-4.11369075e-07,1.23798870e-07
,7.95400078e-07,1.50456393e-06,2.11659498e-06,2.47964074e-06
,2.45192825e-06,1.93391934e-06,8.99783835e-07,-5.78616754e-07
,-2.32207153e-06,-4.05410814e-06,-5.43336198e-06,-6.10670216e-06
,-5.77695575e-06,-4.27471063e-06,-1.62055866e-06,1.93683354e-06
,5.91962675e-06,9.66469459e-06,1.24131204e-05,1.34369476e-05
,1.21857451e-05,8.42818747e-06,2.36000940e-06,-5.34919636e-06
,-1.35911099e-05,-2.09444225e-05,-2.58838524e-05,-2.70476435e-05
,-2.35229997e-05,-1.50982467e-05,-2.42790171e-06,1.29358563e-05
,2.86743292e-05,4.19990784e-05,5.00864814e-05,5.05915666e-05
,4.21581280e-05,2.48294151e-05,2.67056011e-07,-2.82928446e-05
,-5.63795498e-05,-7.89066331e-05,-9.09987956e-05,-8.89060882e-05
,-7.08509515e-05,-3.76430708e-05,7.08430521e-06,5.71145500e-05
,1.04388988e-04,1.40185845e-04,1.56584554e-04,1.47990130e-04
,1.12450591e-04,5.25018118e-05,-2.46757428e-05,-1.07908156e-04
,-1.83476655e-04,-2.37208249e-04,-2.56917499e-04,-2.34808459e-04
,-1.69403732e-04,-6.65982393e-05,6.04579193e-05,1.92770344e-04
,3.08112096e-04,3.84518740e-04,4.04154437e-04,3.56910865e-04
,2.43073761e-04,7.44801293e-05,-1.26210093e-04,-3.28214093e-04
,-4.97046423e-04,-6.00077323e-04,-6.12383080e-04,-5.21898850e-04
,-3.32899837e-04,-6.70249962e-05,2.38596294e-04,5.36094528e-04
,7.73963529e-04,9.05529281e-04,8.97457713e-04,7.36833652e-04
,4.35443394e-04,3.02417240e-05,-4.20456028e-04,-8.44821933e-04
,-1.16844773e-03,-1.32678116e-03,-1.27707569e-03,-1.00775748e-03
,-5.43360163e-04,5.62335007e-05,7.02644193e-04,1.29133622e-03
,1.71784362e-03,1.89547047e-03,1.77158459e-03,1.33960581e-03
,6.44266632e-04,-2.21345553e-04,-1.12718806e-03,-1.92491327e-03
,-2.47124481e-03,-2.65253648e-03,-2.40646733e-03,-1.73696642e-03
,-7.19274083e-04,5.06549919e-04,1.75355536e-03,2.81521742e-03
,3.49834139e-03,3.65650671e-03,3.21849531e-03,2.20653459e-03
,7.40466312e-04,-9.74013500e-04,-2.67239391e-03,-4.07042234e-03
,-4.90970563e-03,-5.00280765e-03,-4.27033176e-03,-2.76320044e-03
,-6.65244106e-04,1.72593671e-03,4.03846409e-03,5.88121249e-03
,6.90663255e-03,6.87173764e-03,5.68715348e-03,3.44526248e-03
,4.21140768e-04,-2.95613127e-03,-6.15963803e-03,-8.64156147e-03
,-9.92031567e-03,-9.66485737e-03,-7.76255006e-03,-4.35845162e-03
,1.42613349e-04,5.11475264e-03,9.78803921e-03,1.33553945e-02
,1.50956622e-02,1.44957443e-02,1.13535360e-02,5.84490527e-03
,-1.45796082e-03,-9.62333646e-03,-1.74508651e-02,-2.36078228e-02
,-2.67950296e-02,-2.59216420e-02,-2.02656904e-02,-9.59798916e-03
,5.74903523e-03,2.48794324e-02,4.64020739e-02,6.85633728e-02
,8.94297987e-02,1.07098658e-01,1.19911410e-01,1.26642940e-01
,1.26642940e-01,1.19911410e-01,1.07098658e-01,8.94297987e-02
,6.85633728e-02,4.64020739e-02,2.48794324e-02,5.74903523e-03
,-9.59798916e-03,-2.02656904e-02,-2.59216420e-02,-2.67950296e-02
,-2.36078228e-02,-1.74508651e-02,-9.62333646e-03,-1.45796082e-03
,5.84490527e-03,1.13535360e-02,1.44957443e-02,1.50956622e-02
,1.33553945e-02,9.78803921e-03,5.11475264e-03,1.42613349e-04
,-4.35845162e-03,-7.76255006e-03,-9.66485737e-03,-9.92031567e-03
,-8.64156147e-03,-6.15963803e-03,-2.95613127e-03,4.21140768e-04
,3.44526248e-03,5.68715348e-03,6.87173764e-03,6.90663255e-03
,5.88121249e-03,4.03846409e-03,1.72593671e-03,-6.65244106e-04
,-2.76320044e-03,-4.27033176e-03,-5.00280765e-03,-4.90970563e-03
,-4.07042234e-03,-2.67239391e-03,-9.74013500e-04,7.40466312e-04
,2.20653459e-03,3.21849531e-03,3.65650671e-03,3.49834139e-03
,2.81521742e-03,1.75355536e-03,5.06549919e-04,-7.19274083e-04
,-1.73696642e-03,-2.40646733e-03,-2.65253648e-03,-2.47124481e-03
,-1.92491327e-03,-1.12718806e-03,-2.21345553e-04,6.44266632e-04
,1.33960581e-03,1.77158459e-03,1.89547047e-03,1.71784362e-03
,1.29133622e-03,7.02644193e-04,5.62335007e-05,-5.43360163e-04
,-1.00775748e-03,-1.27707569e-03,-1.32678116e-03,-1.16844773e-03
,-8.44821933e-04,-4.20456028e-04,3.02417240e-05,4.35443394e-04
,7.36833652e-04,8.97457713e-04,9.05529281e-04,7.73963529e-04
,5.36094528e-04,2.38596294e-04,-6.70249962e-05,-3.32899837e-04
,-5.21898850e-04,-6.12383080e-04,-6.00077323e-04,-4.97046423e-04
,-3.28214093e-04,-1.26210093e-04,7.44801293e-05,2.43073761e-04
,3.56910865e-04,4.04154437e-04,3.84518740e-04,3.08112096e-04
,1.92770344e-04,6.04579193e-05,-6.65982393e-05,-1.69403732e-04
,-2.34808459e-04,-2.56917499e-04,-2.37208249e-04,-1.83476655e-04
,-1.07908156e-04,-2.46757428e-05,5.25018118e-05,1.12450591e-04
,1.47990130e-04,1.56584554e-04,1.40185845e-04,1.04388988e-04
,5.71145500e-05,7.08430521e-06,-3.76430708e-05,-7.08509515e-05
,-8.89060882e-05,-9.09987956e-05,-7.89066331e-05,-5.63795498e-05
,-2.82928446e-05,2.67056011e-07,2.48294151e-05,4.21581280e-05
,5.05915666e-05,5.00864814e-05,4.19990784e-05,2.86743292e-05
,1.29358563e-05,-2.42790171e-06,-1.50982467e-05,-2.35229997e-05
,-2.70476435e-05,-2.58838524e-05,-2.09444225e-05,-1.35911099e-05
,-5.34919636e-06,2.36000940e-06,8.42818747e-06,1.21857451e-05
,1.34369476e-05,1.24131204e-05,9.66469459e-06,5.91962675e-06
,1.93683354e-06,-1.62055866e-06,-4.27471063e-06,-5.77695575e-06
,-6.10670216e-06,-5.43336198e-06,-4.05410814e-06,-2.32207153e-06
,-5.78616754e-07,8.99783835e-07,1.93391934e-06,2.45192825e-06
,2.47964074e-06,2.11659498e-06,1.50456393e-06,7.95400078e-07
,1.23798870e-07,-4.11369075e-07,-7.55719627e-07,-8.98604470e-07
,-8.65065549e-07,-7.03454138e-07,-4.71817378e-07,-2.25712979e-07
,-9.28338958e-09,1.49565363e-07,2.39964381e-07,2.65658969e-07
,2.40567906e-07,1.83624336e-07,1.14026409e-07,4.76801155e-08
,-4.79838043e-09,-3.85424075e-08,-5.36704304e-08,-5.37722144e-08
,-4.41472886e-08,-3.02170690e-08,-1.63857620e-08,-5.45893585e-09
,1.41808699e-09,4.44081220e-09,4.62867609e-09,3.28689029e-09};
/*
const double fir_filter_coef_8x[] =
{1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
*/
const uint32_t size_fir_filter_coef_8x = sizeof(fir_filter_coef_8x) / sizeof(double);


const double coef_bq_filter_8x[][6] = 
{{1.7338132794271178e-07, 2.772345500166761e-07, 1.7338132794271176e-07, 1.0, -0.3257608489900625, 0.0},
{1.0, 0.7713878458875878, 1.0000000000000004, 1.0, -0.6691721833121527, 0.1186150763910248},
{1.0, 0.011449672107653582, 0.9999999999999998, 1.0, -0.7194657890412135, 0.15423014567930665},
{1.0, -0.5378447954718893, 1.0000000000000002, 1.0, -0.795373115450047, 0.2080205255454805},
{1.0, 1.0, 0.0, 1.0, -0.8877476526126259, 0.27355303461674907},
{1.0, -0.9096700350676158, 0.9999999999999999, 1.0, -0.987674238742331, 0.3445590058885283},
{1.0, -1.1609878360367194, 1.0, 1.0, -1.0879972056481526, 0.41600989174923886},
{1.0, -1.3343271813093338, 1.0000000000000002, 1.0, -1.1838355517767198, 0.48448000697209354},
{1.0, -1.4570009127553472, 1.0000000000000002, 1.0, -1.2723876326113985, 0.5480093025014097},
{1.0, -1.5460317296999952, 1.0000000000000002, 1.0, -1.3524274986157285, 0.6057491900492731},
{1.0, -1.6121117211582299, 0.9999999999999998, 1.0, -1.4237734358214624, 0.6575888787224444},
{1.0, -1.6620959497119394, 1.0, 1.0, -1.4868572797221091, 0.7038527255335566},
{1.0, -1.700486112120133, 0.9999999999999999, 1.0, -1.5424224045340469, 0.7450882584315344},
{1.0, -1.7303090095702203, 1.0, 1.0, -1.5913324149514505, 0.7819322514716851},
{1.0, -1.7536438011052389, 1.0, 1.0, -1.634460366935532, 0.8150336542468591},
{1.0, -1.7719448915212261, 1.0, 1.0, -1.6726310618498934, 0.8450141025384562},
{1.0, -1.7862439676058697, 0.9999999999999999, 1.0, -1.7065959601662344, 0.8724516814481151},
{1.0, -1.7972789916026957, 0.9999999999999999, 1.0, -1.737027003762007, 0.8978783804129093},
{1.0, -1.8055779458035717, 0.9999999999999996, 1.0, -1.7645207781820271, 0.9217853301556903},
{1.0, -1.8115137739031102, 1.0000000000000002, 1.0, -1.7896079670114369, 0.9446324338660317},
{1.0, -1.815340401363419, 1.0, 1.0, -1.812765323807076, 0.9668606679792833},
{1.0, -1.8172158195705757, 0.9999999999999998, 1.0, -1.8344288142123897, 0.9889064233556966}};


const uint32_t size_coef_bq_filter_8x = sizeof(coef_bq_filter_8x) / sizeof(double);

union uData
{
   bool b;
   char c;
   unsigned char uc;
   short s;
   unsigned short us;
   int i;
   unsigned int ui;
   float f;
   double d;
   long long int i64;
   unsigned long long int ui64;
   char *str;
   unsigned char *bytes;
};

class RING_BUFFER
{
   public:
   RING_BUFFER(uint32_t);
   int64_t get_size(void);
   int64_t get_read_point(void);
   int64_t get_write_point(void);
   int16_t read(int32_t*);
   int16_t write(int32_t);
   int16_t read_array(int32_t*, uint32_t);
   int16_t write_array(int32_t*, uint32_t);

   private:
   int64_t size_buffer;
   int32_t *buffer;
   int64_t write_point;
   int64_t read_point;
   bool is_buffer_full;
};

RING_BUFFER::RING_BUFFER(uint32_t size)
{
   size_buffer = size;
   buffer = new int32_t[size_buffer];
   write_point = 0;
   read_point = 0;
}

int64_t RING_BUFFER::get_size(void)
{
   return write_point - read_point;
}

int64_t RING_BUFFER::get_read_point(void)
{
   return read_point;
}

int64_t RING_BUFFER::get_write_point(void)
{
   return write_point;
}

int16_t RING_BUFFER::write(int32_t input)
{
   if(write_point - read_point == size_buffer)
      return -1; // buffer is full
   
   buffer[write_point % size_buffer] = input;
   write_point++;
   return 0;
}

int16_t RING_BUFFER::read(int32_t* output)
{
   if(write_point == read_point)
      return -1; // buffer is empty

   *output = buffer[read_point % size_buffer];
   read_point++;
   return 0;
}

int16_t RING_BUFFER::read_array(int32_t* output, uint32_t size)
{
   if(write_point == read_point)
      return -1; // buffer is empty
   
   if(get_size() <size)
      return -1; // now buffer size is not bigger than requester size

   for(uint32_t index=0; index< size; index++)
   {
      int64_t error_code = read(output++);
      if(error_code!=0)
         return -1;
   }
   return 0;
}

int16_t RING_BUFFER::write_array(int32_t* input, uint32_t size)
{
   if(write_point - read_point == size_buffer)
      return -1; // buffer is full
   
   for(uint32_t index=0; index< size; index++)
   {
      int64_t error_code = write(*(input++));
      if(error_code!=0)
         return -1;
   }
   return 0;
}

uint32_t separate_ch(int32_t* p_in, int32_t* p_out, uint32_t length, uint8_t target_ch, uint8_t num_ch)
{
   uint32_t counter = 0;
   for(uint32_t i = 0; i < length; i++)
   {
      if(i % num_ch == target_ch)
      {
         p_out[counter] = p_in[i];
         counter++;
      }
   }
   return counter;
}

uint32_t connect_2ch(int32_t* p_in0, int32_t* p_in1, int32_t* p_out, uint32_t length)
{
   uint32_t out_index = 0;
   for(uint32_t i=0; i<length; i++)
   {
      *p_out++ = *p_in0++;
      *p_out++ = *p_in1++;
      out_index+=2;
   }
   return out_index;
}

// oversampling NOS
uint32_t NOS_filter(uint32_t length, int32_t* p_in, int32_t* p_out, uint8_t oversampling_ratio)
{
   uint32_t count_out_size = 0;
   uint32_t length_buffer = length >>1;
   while(length_buffer--)
   {
      for(int i=0; i<oversampling_ratio; i++)
      {
         *p_out++ = *p_in++;
         *p_out++ = *p_in--;
         count_out_size+=2;
      }
      p_in+=2;
   }
   return count_out_size;
}

// oversampling FIR 2ch ver
uint32_t FIR_filter_2ch(uint32_t length, int32_t* p_in, int32_t* p_out, double* delay, const double* h, const uint16_t size_tap)
{
   int count_out_size = 0;
   for(int32_t sample=0; sample<length; sample++)
   {
      double temporary = 0;

      uint8_t ch = sample - (sample>>1) * 2;
      *(delay + ch * size_tap) = p_in[sample];

      for(int32_t tap=0; tap < size_tap; tap++)
         temporary += h[tap] * (*(delay + ch * size_tap + tap));
      
      for(int32_t tap=size_tap-1; tap > 0; tap--)
         *(delay + ch * size_tap + tap) = *(delay + ch * size_tap + tap - 1);

      p_out[sample] = (int32_t)temporary;
      count_out_size++;
   }
   return count_out_size;
}

// oversampling biquad IIR filter
uint32_t IIR_BQ_filter_2ch(uint32_t length, int32_t* p_in, int32_t* p_out, double* delay_, const double* k_, const uint16_t size_tap)
{
   int count_out_size = 0;
   for(int32_t sample=0; sample<length; sample++)
   {
      uint8_t ch = sample % 2;
      double temporary = (double)p_in[sample];
      for(int32_t tap=0; tap<size_tap; tap++)
      {
         double* delay = delay_ + size_tap * 4 * ch + tap * 4;
         double* k = (double*)k_ + tap * 6;
         double temporary_old = temporary;

         temporary = temporary * (*(k + 0)) + *(delay + 0) * (*(k + 1))
                                    + *(delay + 1) * (*(k + 2))
                                    - *(delay + 2) * (*(k + 4))
                                    - *(delay + 3) * (*(k + 5));
         
         *(delay + 1) = *(delay + 0);
         *(delay + 0) = temporary_old;
         *(delay + 3) = *(delay + 2);
         *(delay + 2) = temporary;
      }

      p_out[sample] = (int32_t)temporary;
      count_out_size++;
   }
   return count_out_size;
}

// int DllMain() must exist and return 1 for a process to load the .DLL
// See https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain for more information.
int __stdcall DllMain(void *module, unsigned int reason, void *reserved) { return 1; }

// #undef pin names lest they collide with names in any header file(s) you might include.
#undef signal_in0
#undef signal_in1
#undef push_buffer
#undef clock
#undef debug1
#undef debug2
#undef debug3
#undef output0
#undef output1

DEBUG_INNER_FUNC debug_infuc1;

static bool is_initialized = false;

RING_BUFFER usb_buffer(SIZE_USB_BUFFER);
RING_BUFFER oversampling_buffer(SIZE_OUTPUT_BUFFER);
RING_BUFFER output_buffer(SIZE_OUTPUT_BUFFER);

static unsigned char clock_old = 0;
static unsigned char push_buffer_old  =0;
static uint32_t prescale_counter = 0;
static bool can_output = false;
static bool can_write_usb_buffer = false;
static uint32_t prescale_counter2 = 0;

//static double* fir_delay_buffer = (double*)malloc(sizeof(double) * size_fir_filter_coef_8x * 2);
static double* bq_delay_buffer = (double*)malloc(sizeof(double) * size_coef_bq_filter_8x / 6 * 4 * 2);
//static double* coef_bq_filter_for_calc = (double*)malloc(sizeof(double) * size_coef_bq_filter_8x / 6 * 5);

extern "C" __declspec(dllexport) void digitalfilter_x1(void **opaque, double t, union uData *data)
{
   double        signal_in0  = data[0].d ; // input
   double        signal_in1  = data[1].d ; // input
   unsigned char push_buffer = data[2].uc; // input
   unsigned char clock       = data[3].uc; // input
   double       &debug1      = data[4].d ; // output
   double       &debug2      = data[5].d ; // output
   double       &debug3      = data[6].d ; // output
   double       &output0     = data[7].d ; // output
   double       &output1     = data[8].d ; // output

// Implement module evaluation code here:

   if(!is_initialized)
   {
      //initialize_bq_filte_params((const double*)coef_bq_filter_8x, coef_bq_filter_for_calc, size_coef_bq_filter_8x);
      memset(bq_delay_buffer, 0, size_coef_bq_filter_8x / 6 * 4 * 2);

      //for(int32_t i=0; i<8; i++)
      //   debug_infuc1.debug[i] = 0;

      is_initialized = true;
   }

   // scheduler
   if(clock == 1 && clock_old == 0)
   {
      can_output = true;
      if(prescale_counter >= RATIO_OVERSAMPLING)
      {
         can_write_usb_buffer = true;
         prescale_counter = 0;
      }
      prescale_counter++;
   }
   clock_old = clock;

   // input USB buffer
   if(can_write_usb_buffer)
   {
      int16_t is_buffer_full = 0;
      is_buffer_full |= usb_buffer.write((int32_t)signal_in0);
      is_buffer_full |= usb_buffer.write((int32_t)signal_in1);
      //debug1 = is_buffer_full;
      can_write_usb_buffer = false;
   }

   // output USB buffer and oversampling
   if(push_buffer == 1 && push_buffer_old == 0)
   {
      // USB dequeue
      uint32_t size_buffer = usb_buffer.get_size();
      //debug1 = size_buffer;
      int32_t* usb_dequeue_buffer = (int32_t*)malloc(sizeof(int32_t) * size_buffer);
      usb_buffer.read_array(usb_dequeue_buffer, size_buffer);
      
      oversampling_buffer.write_array(usb_dequeue_buffer, size_buffer);
      free(usb_dequeue_buffer);

      if(prescale_counter2 >= OVERSAMPLING_TIMING_PRESCALE)
      {
         // acq oversampling data
         //debug2 = oversampling_buffer.get_size();
         uint32_t size_filter_input_buffer = oversampling_buffer.get_size();
         int32_t* filter_input_buffer = (int32_t*)malloc(sizeof(int32_t) * size_filter_input_buffer);
         oversampling_buffer.read_array(filter_input_buffer, size_filter_input_buffer);

         // oversampling
         uint32_t size_NOS_buffer = size_filter_input_buffer * RATIO_OVERSAMPLING;
         //debug2 = size_NOS_buffer;
         int32_t* NOS_buffer = (int32_t*)malloc(sizeof(int32_t) * size_NOS_buffer);
         NOS_filter(size_filter_input_buffer, filter_input_buffer, NOS_buffer, RATIO_OVERSAMPLING);
         free(filter_input_buffer);
         int32_t* output_buffer_pre = (int32_t*)malloc(sizeof(int32_t) * size_NOS_buffer);
         /*
         uint32_t size_output_buffer = FIR_filter_2ch(size_NOS_buffer, 
                                                      NOS_buffer,
                                                      output_buffer_pre,
                                                      fir_delay_buffer,
                                                      fir_filter_coef_8x,
                                                      size_fir_filter_coef_8x);
         */
         
         uint32_t size_output_buffer = IIR_BQ_filter_2ch(size_NOS_buffer, 
                                                      NOS_buffer,
                                                      output_buffer_pre,
                                                      bq_delay_buffer,
                                                      (const double*)coef_bq_filter_8x,
                                                      size_coef_bq_filter_8x / 6);
         
         //debug1 = debug_infuc1.debug[0];
         //debug2 = debug_infuc1.debug[1];
         //debug3 = debug_infuc1.debug[2];
         
         free(NOS_buffer);

         // packing output buffer
         output_buffer.write_array(output_buffer_pre, size_output_buffer);
         free(output_buffer_pre);

         prescale_counter2 = 0;
      }
      prescale_counter2++;
   }
   push_buffer_old = push_buffer;

   // output
   if(can_output)
   {
      //debug3 = output_buffer.get_size();

      for(int16_t i=0; i<2; i++)
      {
         if(output_buffer.get_size() >0)
         {
            int32_t out_buffer = 0;
            if(output_buffer.get_read_point() % 2 == 0)
            {
               output_buffer.read(&out_buffer);
               output0 = (double)out_buffer;
            }
            else
            {
               output_buffer.read(&out_buffer);
               output1 = (double)out_buffer;
            }
         }
      }
      can_output = false;
   }
}
