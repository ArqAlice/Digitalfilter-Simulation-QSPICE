// Automatically generated C++ file on Thu Oct 24 18:58:38 2024
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD digitalfilter_x1.cpp kernel32.lib
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RATIO_OVERSAMPLING 32
#define SIZE_USB_BUFFER 256
#define SIZE_OUTPUT_BUFFER 8192
#define OVERSAMPLING_TIMING_PRESCALE 1

#define RATIO_OVERSAMPLING0 4
#define RATIO_OVERSAMPLING1 2
#define RATIO_OVERSAMPLING2 4

typedef struct
{
   double debug[8];
} DEBUG_INNER_FUNC;

// Filter Params

// FIR 4x filter0  44.1k/48k to 176.4k/192k
const double coef_fir_filter_4x_0[] =
    {8.564405566961502e-06, 7.404604056595376e-05, 0.00036266640066355695, 0.001299162100418252, 0.0037516666321589518, 0.00917793794861192,
     0.01957952157841827, 0.037085849824722704, 0.06307301287985731, 0.09693950909637042, 0.13496213556504724, 0.16989354176822852,
     0.19194578910576668, 0.19139849242940513, 0.16232366554500807, 0.10611675385574962, 0.03310736637665369, -0.039119068335427526,
     -0.09085501338237632, -0.10737566840530458, -0.08520632574959447, -0.03454757752055591, 0.023846169452172498, 0.06662719374435583,
     0.07750031955068441, 0.054213226063343514, 0.009430969015185822, -0.035225967609010256, -0.05935536362602635, -0.05330405098608827,
     -0.022359048392711134, 0.01648704454938504, 0.04349671115392817, 0.046207617121814926, 0.025324854219176497, -0.0064511174162168415,
     -0.03178243307868141, -0.038076007017426305, -0.023783729193226848, 0.0016049050442344007, 0.02351026956241449, 0.030539178363772124,
     0.02039692509435478, 0.0003411282910698735, -0.01766738073423981, -0.02399958459618219, -0.016463324005388476, -0.0007766038629624279,
     0.013441474046951297, 0.018473631047710777, 0.012631496939284694, 0.0005252428543107452, -0.010274712126301499, -0.013881179739024599,
     -0.009226425937018964, -6.026978369496684e-05, 0.007814613891345848, 0.010132533476039388, 0.006396312767382138, -0.00036713790562056434,
     -0.005853228198687779, -0.007144516988118204, -0.004181103840183728, 0.0006482831767097956, 0.004275042797634761, 0.004835651242425845,
     0.002549595695699662, -0.000763058750008358, -0.0030168406655575377, -0.0031193752773236555, -0.0014251803330043577, 0.0007406111828244994,
     0.002039261821354295, 0.001901680311395796, 0.0007073392722440584, -0.0006303435527589394, -0.001309102757138179, -0.0010839327903925558,
     -0.000290039895166873, 0.0004820188727531417, 0.0007907723140488186, 0.0005691317988247049, 7.60199625362688e-05, -0.00033430439199916555,
     -0.00044462371309301064, -0.000269029375443417, 1.4142544294188902e-05, 0.000210545279841795, 0.0002294470426480122, 0.00010983190386153442,
     -3.8388483558589254e-05, -0.00011981229726634057, -0.00010649333219390201, -3.5127543354271343e-05, 3.4109785139675654e-05, 6.08912591947545e-05,
     4.30081326648609e-05, 5.789944825000704e-06, -2.206000691078022e-05, -2.7059093852554193e-05, -1.4161574964532e-05, 2.49455949031935e-06,
     1.1457150403262079e-05, 1.0113382174536351e-05, 3.166479897976295e-06, -2.961392056315317e-06, -4.803359818393535e-06, -2.9272486480670096e-06,
     -2.475164749386721e-08, 1.6455190895075981e-06, 1.544802103112426e-06, 5.062801228491597e-07, -3.80963780550024e-07, -6.035983268357457e-07,
     -3.214031469533204e-07, 3.676610654836328e-08, 1.8923323271222424e-07, 1.3185575297106159e-07, 1.1757411884962533e-08, -5.162984086081841e-08,
     -4.143686752457605e-08, -4.970688922625634e-09, 1.4789229734804425e-08, 1.0044371520647718e-08, -2.4394975483586873e-09, -3.496525474792943e-09,
     6.576436052612324e-10, 2.377579249192807e-10};

const uint32_t size_coef_fir_filter_4x_0 = sizeof(coef_fir_filter_4x_0) / sizeof(double);

// FIR 2x filter1  88.2k/96k to 176.4k/192k
const double coef_fir_filter_2x_1[] =
    {-9.487966163104853e-10, -3.5340924713787084e-09, 4.2726994320443245e-08, 1.3090689733882082e-07, -2.2939270286939258e-07, -1.518209169374895e-06,
     -1.676408401526929e-06, 4.729124291082094e-06, 1.7683314132634787e-05, 1.638726703834121e-05, -3.3577372621264804e-05, -0.00012270230405724014,
     -0.00013262201992526588, 0.00010618777396987576, 0.0005632025915198933, 0.0007699887185120032, 3.776474106860893e-05, -0.0017011106210167515,
     -0.0030958204634353023, -0.0018714865939526801, 0.002925774169318973, 0.00855400259910473, 0.00907494568871351, 9.455934469275386e-05,
     -0.015249553448507968, -0.025198038320748274, -0.01689897667620495, 0.011380752057310525, 0.043745943458961135, 0.054188092486256105,
     0.02551690798276319, -0.03401828440051029, -0.09083769412674561, -0.10533368603089906, -0.05755639560388964, 0.03911997641415518,
     0.14580390607737992, 0.2209550550852799, 0.24208720183672777, 0.21316488764332628, 0.1562901984488822, 0.09646656357981995,
     0.049991614557148484, 0.021443941069533172, 0.0073986748359036875, 0.0019479035135361207, 0.0003523537145792295, 3.3360564843645475e-05};

const uint32_t size_coef_fir_filter_2x_1 = sizeof(coef_fir_filter_2x_1) / sizeof(double);

// BQ-IIR 2x filter2  176.4k/192k to 352.8k/384k
const double coef_bq_filter_2x_2[][6] =
    {{7.331409658980419e-06, 1.3658751350342684e-05, 7.331409658980423e-06, 1.0, -1.2816769353089004, 0.41422377350564477},
     {1.0, 1.106773090818239, 1.0, 1.0, -1.3472004160176496, 0.48473097896656375},
     {1.0, 0.43313123434498524, 1.0, 1.0, -1.4801044276329434, 0.6285025578761835},
     {1.0, 0.10967205424069733, 1.0, 1.0, -1.6862717576220687, 0.8532309485716787}};

const uint32_t size_coef_bqfilter_2x_2 = sizeof(coef_bq_filter_2x_2) / sizeof(double);

// BQ-IIR 4x filter0  352.8k/384k to 1411.2k/1536k
const double coef_bq_filter_4x_0[][6] =
    {{5.387756499116675e-07, 5.295041771639956e-07, 5.387756499116674e-07, 1.0, -1.8012094984621612, 0.8117345477897354},
     {1.0, -0.8717934351807886, 1.0, 1.0, -1.84871679612354, 0.8594503158324095},
     {1.0, -1.3043326329001699, 1.0000000000000002, 1.0, -1.9353227815837257, 0.94648768126873}};

const uint32_t size_coef_bq_filter_4x_0 = sizeof(coef_bq_filter_4x_0) / sizeof(double);

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
   int16_t read(int32_t *);
   int16_t write(int32_t);
   int16_t read_array(int32_t *, uint32_t);
   int16_t write_array(int32_t *, uint32_t);

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
   if (write_point - read_point == size_buffer)
      return -1; // buffer is full

   buffer[write_point % size_buffer] = input;
   write_point++;
   return 0;
}

int16_t RING_BUFFER::read(int32_t *output)
{
   if (write_point == read_point)
      return -1; // buffer is empty

   *output = buffer[read_point % size_buffer];
   read_point++;
   return 0;
}

int16_t RING_BUFFER::read_array(int32_t *output, uint32_t size)
{
   if (write_point == read_point)
      return -1; // buffer is empty

   if (get_size() < size)
      return -1; // now buffer size is not bigger than requester size

   for (uint32_t index = 0; index < size; index++)
   {
      int64_t error_code = read(output++);
      if (error_code != 0)
         return -1;
   }
   return 0;
}

int16_t RING_BUFFER::write_array(int32_t *input, uint32_t size)
{
   if (write_point - read_point == size_buffer)
      return -1; // buffer is full

   for (uint32_t index = 0; index < size; index++)
   {
      int64_t error_code = write(*(input++));
      if (error_code != 0)
         return -1;
   }
   return 0;
}

uint32_t separate_ch(int32_t *p_in, int32_t *p_out, uint32_t length, uint8_t target_ch, uint8_t num_ch)
{
   uint32_t counter = 0;
   for (uint32_t i = 0; i < length; i++)
   {
      if (i % num_ch == target_ch)
      {
         p_out[counter] = p_in[i];
         counter++;
      }
   }
   return counter;
}

uint32_t connect_2ch(int32_t *p_in0, int32_t *p_in1, int32_t *p_out, uint32_t length)
{
   uint32_t out_index = 0;
   for (uint32_t i = 0; i < length; i++)
   {
      *p_out++ = *p_in0++;
      *p_out++ = *p_in1++;
      out_index += 2;
   }
   return out_index;
}

// oversampling NOS
uint32_t NOS_filter(uint32_t length, int32_t *p_in, int32_t *p_out, uint8_t oversampling_ratio)
{
   uint32_t length_buffer = length;
   while (length_buffer--)
   {
      for (int i = 0; i < oversampling_ratio - 1; i++)
         *p_out++ = *p_in;
      *p_out++ = *(p_in++);
   }
   return length * oversampling_ratio;
}

// oversampling FIR 1ch ver
uint32_t FIR_filter(uint32_t length, int32_t *p_in, int32_t *p_out, double *delay, const double *h, const uint16_t size_tap)
{
   int count_out_size = 0;
   for (int sample = 0; sample < length; sample++)
   {
      double temporary = 0;

      *delay = (double)p_in[sample];

      for (int tap = 0; tap < size_tap; tap++)
         temporary += h[tap] * (*(delay + tap));

      for (int tap = size_tap - 1; tap > 0; tap--)
         *(delay + tap) = *(delay + tap - 1);

      p_out[sample] = (int32_t)temporary;
      count_out_size++;
   }
   return count_out_size;
}

// oversampling biquad IIR filter 1ch ver
uint32_t IIR_BQ_filter(uint32_t length, int32_t *p_in, int32_t *p_out, double *delay_, const double *k_, const uint16_t size_tap)
{
   int count_out_size = 0;
   for (int32_t sample = 0; sample < length; sample++)
   {
      double temporary = (double)p_in[sample];
      for (int32_t tap = 0; tap < size_tap; tap++)
      {
         double *delay = delay_ + tap * 4;
         double *k = (double *)k_ + tap * 6;
         double temporary_old = temporary;

         temporary = temporary * (*(k + 0)) + *(delay + 0) * (*(k + 1)) + *(delay + 1) * (*(k + 2)) - *(delay + 2) * (*(k + 4)) - *(delay + 3) * (*(k + 5));

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

RING_BUFFER usb_buffer_L(SIZE_USB_BUFFER);
RING_BUFFER usb_buffer_R(SIZE_USB_BUFFER);
RING_BUFFER oversampling_buffer_L(SIZE_OUTPUT_BUFFER);
RING_BUFFER oversampling_buffer_R(SIZE_OUTPUT_BUFFER);
RING_BUFFER output_buffer_L(SIZE_OUTPUT_BUFFER);
RING_BUFFER output_buffer_R(SIZE_OUTPUT_BUFFER);

static unsigned char clock_old = 0;
static unsigned char push_buffer_old = 0;
static uint32_t prescale_counter = 0;
static bool can_output = false;
static bool can_write_usb_buffer = false;
static uint32_t prescale_counter2 = 0;

static double *fir_delay_buffer_L = (double *)malloc(sizeof(double) * size_coef_fir_filter_4x_0);
static double *fir_delay_buffer_R = (double *)malloc(sizeof(double) * size_coef_fir_filter_4x_0);
static double *bq_delay_buffer_L_0 = (double *)malloc(sizeof(double) * size_coef_bqfilter_2x_2 / 6 * 4);
static double *bq_delay_buffer_R_0 = (double *)malloc(sizeof(double) * size_coef_bqfilter_2x_2 / 6 * 4);
static double *bq_delay_buffer_L_1 = (double *)malloc(sizeof(double) * size_coef_bq_filter_4x_0 / 6 * 4);
static double *bq_delay_buffer_R_1 = (double *)malloc(sizeof(double) * size_coef_bq_filter_4x_0 / 6 * 4);

extern "C" __declspec(dllexport) void digitalfilter_x1(void **opaque, double t, union uData *data)
{
   double signal_in0 = data[0].d;          // input
   double signal_in1 = data[1].d;          // input
   unsigned char push_buffer = data[2].uc; // input
   unsigned char clock = data[3].uc;       // input
   double &debug1 = data[4].d;             // output
   double &debug2 = data[5].d;             // output
   double &debug3 = data[6].d;             // output
   double &output0 = data[7].d;            // output
   double &output1 = data[8].d;            // output

   // Implement module evaluation code here:

   if (!is_initialized)
   {
      // initialize delay buffers
      memset(fir_delay_buffer_L, 0, sizeof(double) * size_coef_fir_filter_4x_0);
      memset(fir_delay_buffer_R, 0, sizeof(double) * size_coef_fir_filter_4x_0);
      memset(bq_delay_buffer_L_0, 0, sizeof(double) * size_coef_bqfilter_2x_2 / 6 * 4);
      memset(bq_delay_buffer_R_0, 0, sizeof(double) * size_coef_bqfilter_2x_2 / 6 * 4);
      memset(bq_delay_buffer_L_1, 0, sizeof(double) * size_coef_bq_filter_4x_0 / 6 * 4);
      memset(bq_delay_buffer_R_1, 0, sizeof(double) * size_coef_bq_filter_4x_0 / 6 * 4);

      is_initialized = true;
   }

   // scheduler
   if (clock == 1 && clock_old == 0)
   {
      can_output = true;
      if (prescale_counter >= RATIO_OVERSAMPLING)
      {
         can_write_usb_buffer = true;
         prescale_counter = 0;
      }
      prescale_counter++;
   }
   clock_old = clock;

   // input USB buffer
   if (can_write_usb_buffer)
   {
      int16_t is_buffer_full_L = 0;
      int16_t is_buffer_full_R = 0;

      is_buffer_full_L |= usb_buffer_L.write((int32_t)signal_in0);
      is_buffer_full_R |= usb_buffer_R.write((int32_t)signal_in1);
      // debug1 = is_buffer_full_L;
      can_write_usb_buffer = false;
   }

   // output USB buffer and oversampling
   if (push_buffer == 1 && push_buffer_old == 0)
   {
      // USB dequeue
      uint32_t size_buffer = usb_buffer_L.get_size();
      debug1 = size_buffer;
      int32_t *usb_dequeue_buffer_L = (int32_t *)malloc(sizeof(int32_t) * size_buffer);
      int32_t *usb_dequeue_buffer_R = (int32_t *)malloc(sizeof(int32_t) * size_buffer);
      usb_buffer_L.read_array(usb_dequeue_buffer_L, size_buffer);
      usb_buffer_R.read_array(usb_dequeue_buffer_R, size_buffer);

      // Prepareing buffers
      int32_t *NOS_buffer_L = (int32_t *)malloc(sizeof(int32_t) * size_buffer * RATIO_OVERSAMPLING);
      int32_t *NOS_buffer_R = (int32_t *)malloc(sizeof(int32_t) * size_buffer * RATIO_OVERSAMPLING);
      int32_t *output_pre_buffer_L = (int32_t *)malloc(sizeof(int32_t) * size_buffer * RATIO_OVERSAMPLING);
      int32_t *output_pre_buffer_R = (int32_t *)malloc(sizeof(int32_t) * size_buffer * RATIO_OVERSAMPLING);

      // upsampling0 : 44.1kHz to 176.4kHz
      uint32_t size_NOS0 = NOS_filter(size_buffer, usb_dequeue_buffer_L, NOS_buffer_L, RATIO_OVERSAMPLING0);
      NOS_filter(size_buffer, usb_dequeue_buffer_R, NOS_buffer_R, RATIO_OVERSAMPLING0);

      uint32_t size_filter0_out = FIR_filter(size_NOS0,
                                             NOS_buffer_L,
                                             output_pre_buffer_L,
                                             fir_delay_buffer_L,
                                             coef_fir_filter_4x_0,
                                             size_coef_fir_filter_4x_0);

      FIR_filter(size_NOS0,
                 NOS_buffer_R,
                 output_pre_buffer_R,
                 fir_delay_buffer_R,
                 coef_fir_filter_4x_0,
                 size_coef_fir_filter_4x_0);
      
      // upsampling1 : 176.4kHz to 352.8kHz
      uint32_t size_NOS1 = NOS_filter(size_filter0_out, output_pre_buffer_L, NOS_buffer_L, RATIO_OVERSAMPLING1);
      NOS_filter(size_filter0_out, output_pre_buffer_R, NOS_buffer_R, RATIO_OVERSAMPLING1);

      uint32_t size_filter1_out = IIR_BQ_filter(size_NOS1,
                                                NOS_buffer_L,
                                                output_pre_buffer_L,
                                                bq_delay_buffer_L_0,
                                                (const double *)coef_bq_filter_2x_2,
                                                size_coef_bqfilter_2x_2 / 6);

      IIR_BQ_filter(size_NOS1,
                    NOS_buffer_R,
                    output_pre_buffer_R,
                    bq_delay_buffer_R_0,
                    (const double *)coef_bq_filter_2x_2,
                    size_coef_bqfilter_2x_2 / 6);
      
      // upsampling2 : 352.8kHz to 1411.2kHz
      uint32_t size_NOS2 = NOS_filter(size_filter1_out, output_pre_buffer_L, NOS_buffer_L, RATIO_OVERSAMPLING2);
      NOS_filter(size_filter1_out, output_pre_buffer_R, NOS_buffer_R, RATIO_OVERSAMPLING2);

      uint32_t size_filter2_out = IIR_BQ_filter(size_NOS2,
                                                NOS_buffer_L,
                                                output_pre_buffer_L,
                                                bq_delay_buffer_L_1,
                                                (const double *)coef_bq_filter_4x_0,
                                                size_coef_bq_filter_4x_0 / 6);

      IIR_BQ_filter(size_NOS2,
                    NOS_buffer_R,
                    output_pre_buffer_R,
                    bq_delay_buffer_R_1,
                    (const double *)coef_bq_filter_4x_0,
                    size_coef_bq_filter_4x_0 / 6);
      
      // packing output buffer
      output_buffer_L.write_array(output_pre_buffer_L, size_filter2_out);
      output_buffer_R.write_array(output_pre_buffer_R, size_filter2_out);

      free(usb_dequeue_buffer_L);
      free(usb_dequeue_buffer_R);
      free(NOS_buffer_L);
      free(NOS_buffer_R);
      free(output_pre_buffer_L);
      free(output_pre_buffer_R);
   }
   push_buffer_old = push_buffer;

   // output
   if (can_output)
   {
      // debug3 = output_buffer_L.get_size();
      if (output_buffer_L.get_size() > 0)
      {
         int32_t out_buffer = 0;

         output_buffer_L.read(&out_buffer);
         output0 = (double)out_buffer;

         output_buffer_R.read(&out_buffer);
         output1 = (double)out_buffer;
      }
      can_output = false;
   }
}
