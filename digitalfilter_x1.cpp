// Automatically generated C++ file on Thu Oct 24 18:58:38 2024
//
// To build with Digital Mars C++ Compiler:
//
//    dmc -mn -WD digitalfilter_x1.cpp kernel32.lib
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define RATIO_UPSAMPLING0 (4)
#define RATIO_UPSAMPLING1 (2)
#define RATIO_UPSAMPLING2 (4)

#define RATIO_UPSAMPLING (32)
#define SIZE_USB_BUFFER (256)
#define SIZE_OUTPUT_BUFFER (SIZE_USB_BUFFER * RATIO_UPSAMPLING0 * RATIO_UPSAMPLING1 * RATIO_UPSAMPLING2)
#define OVERSAMPLING_TIMING_PRESCALE (1)

#define GAIN_ANTICLIPPING (0.72)

// Filter Params

// FIR 4x filter0  44.1k/48k to 176.4k/192k
const float coef_fir_filter_4x_0[] =
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

const uint32_t size_coef_fir_filter_4x_0 = sizeof(coef_fir_filter_4x_0) / sizeof(float);

// FIR 2x filter1  88.2k/96k to 176.4k/192k
const float coef_fir_filter_2x_1[] =
    {-9.487966163104853e-10, -3.5340924713787084e-09, 4.2726994320443245e-08, 1.3090689733882082e-07, -2.2939270286939258e-07, -1.518209169374895e-06,
     -1.676408401526929e-06, 4.729124291082094e-06, 1.7683314132634787e-05, 1.638726703834121e-05, -3.3577372621264804e-05, -0.00012270230405724014,
     -0.00013262201992526588, 0.00010618777396987576, 0.0005632025915198933, 0.0007699887185120032, 3.776474106860893e-05, -0.0017011106210167515,
     -0.0030958204634353023, -0.0018714865939526801, 0.002925774169318973, 0.00855400259910473, 0.00907494568871351, 9.455934469275386e-05,
     -0.015249553448507968, -0.025198038320748274, -0.01689897667620495, 0.011380752057310525, 0.043745943458961135, 0.054188092486256105,
     0.02551690798276319, -0.03401828440051029, -0.09083769412674561, -0.10533368603089906, -0.05755639560388964, 0.03911997641415518,
     0.14580390607737992, 0.2209550550852799, 0.24208720183672777, 0.21316488764332628, 0.1562901984488822, 0.09646656357981995,
     0.049991614557148484, 0.021443941069533172, 0.0073986748359036875, 0.0019479035135361207, 0.0003523537145792295, 3.3360564843645475e-05};

const uint32_t size_coef_fir_filter_2x_1 = sizeof(coef_fir_filter_2x_1) / sizeof(float);

// BQ-IIR 2x filter2  176.4k/192k to 352.8k/384k
const float coef_bq_filter_2x_2[][6] =
    {{7.331409658980419e-06, 1.3658751350342684e-05, 7.331409658980423e-06, 1.0, -1.2816769353089004, 0.41422377350564477},
     {1.0, 1.106773090818239, 1.0, 1.0, -1.3472004160176496, 0.48473097896656375},
     {1.0, 0.43313123434498524, 1.0, 1.0, -1.4801044276329434, 0.6285025578761835},
     {1.0, 0.10967205424069733, 1.0, 1.0, -1.6862717576220687, 0.8532309485716787}};

const uint32_t size_coef_bq_filter_2x_2 = sizeof(coef_bq_filter_2x_2) / sizeof(float);

// BQ-IIR 4x filter0  352.8k/384k to 1411.2k/1536k
const float coef_bq_filter_4x_3[][6] =
    {{5.387756499116675e-07, 5.295041771639956e-07, 5.387756499116674e-07, 1.0, -1.8012094984621612, 0.8117345477897354},
     {1.0, -0.8717934351807886, 1.0, 1.0, -1.84871679612354, 0.8594503158324095},
     {1.0, -1.3043326329001699, 1.0000000000000002, 1.0, -1.9353227815837257, 0.94648768126873}};

const uint32_t size_coef_bq_filter_4x_3 = sizeof(coef_bq_filter_4x_3) / sizeof(float);

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

void int32_to_float_array(int32_t *input, float *output, uint32_t length)
{
   for(int i=0; i<length; i++)
      output[i] = (float)input[i];
}

void float_to_int32_array(float *input, int32_t *output, uint32_t length)
{
   for(int i=0; i<length; i++)
      output[i] = (int32_t)input[i];
}

void f32_scale_array(float* input, float* output, float gain, uint32_t length)
{
   for(int i=0; i<length; i++)
      output[i] = input[i] * gain;
}

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

class FIR_FILTER
{
public:
   FIR_FILTER(const uint32_t size, uint32_t upsampling_ratio, const float* h_)
   {
      h = new float[size];
      delay = new float[size];
      size_tap = size;
      ratio = upsampling_ratio;
      memcpy(h, h_, sizeof(float) * size);
      memset(delay, 0, sizeof(float) * size);
   };

   void reset_delay(void)
   {
      memset(delay, 0, sizeof(float) * size_tap);
   };

   uint32_t interporate(uint32_t length, float* p_in, float* p_out)
   {
      uint32_t length_buffer = length;
      float* p_in_buf = p_in;
      float* nos = new float[length * ratio];
      float * p_nos_buf = nos;

      // データの長さ(length)の数だけ繰り返す
      while (length_buffer--)
      {
         *p_nos_buf++ = *(p_in_buf++);
         // 0をupsampling_ratio回だけ繰り返す
         for (int i = 0; i < ratio - 1; i++)
            *p_nos_buf++ = *p_in_buf;
      }

      // データの長さ(length)の数だけ繰り返す
      for (int sample = 0; sample < length * ratio; sample++)
      {
         float temporary = 0;

         *delay = nos[sample];

         // FIRフィルタ演算 タップ数の数だけ足しこんでいく
         for (int i = 0; i < size_tap; i++)
            temporary += h[i] * (*(delay + i));

         // 遅延データの更新
         //for (int i = size_tap - 1; i > 0; i--)
         //   *(delay + i) = *(delay + i - 1);
         memcpy(delay + 1, delay, sizeof(float) * (size_tap - 1));

         p_out[sample] = temporary; // 演算結果を出力
      }
      return length * ratio;
   }

private:
   float* h;
   float* delay;
   uint32_t size_tap;
   uint32_t ratio;
};

class IIR_FILTER
{
public:
   IIR_FILTER(const uint32_t size, uint32_t upsampling_ratio, const float* k_)
   {
      k_ = new float[size];
      size_k = size;
      size_delay = size / 6 * 4;
      delay = new float[size_delay];
      ratio = upsampling_ratio;
      memcpy(k, k_, sizeof(float) * size_k);
      memset(delay, 0, sizeof(float) * size_delay);
   };

   void reset_delay(void)
   {
      memset(delay, 0, sizeof(float) * size_delay);
   };

   uint32_t interporate(uint32_t length, float* p_in, float* p_out)
   {
      uint32_t length_buffer = length;
      float* p_in_buf = p_in;
      float* nos = new float[length * ratio];
      float * p_nos_buf = nos;

      // データの長さ(length)の数だけ繰り返す
      while (length_buffer--)
      {
         *p_nos_buf++ = *(p_in_buf++);
         // 0をupsampling_ratio回だけ繰り返す
         for (int i = 0; i < ratio - 1; i++)
            *p_nos_buf++ = *p_in_buf;
      }

      // データの長さ(length)の数だけ繰り返す
      for (int32_t sample = 0; sample < length; sample++)
      {
         float temporary = nos[sample]; // FIRにおけるある時点での値

         // 段数(size_k / 6)の分だけフィルタ演算を繰り返す
         for (int32_t tap = 0; tap < size_k / 6; tap++)
         {
            float *delay = delay + tap * 4;
            float *k_ = k + tap * 6;
            float temporary_old = temporary;

            // IIRフィルタ演算
            temporary = temporary * (*(k_ + 0)) + *(delay + 0) * (*(k_ + 1)) + *(delay + 1) * (*(k_ + 2)) - *(delay + 2) * (*(k_ + 4)) - *(delay + 3) * (*(k_ + 5));

            // 遅延データの更新
            *(delay + 1) = *(delay + 0);
            *(delay + 0) = temporary_old;
            *(delay + 3) = *(delay + 2);
            *(delay + 2) = temporary;
         }

         p_out[sample] = (int32_t)temporary; // 演算結果を出力
      }
      return length * ratio;
   }

private:
   float* k;
   float* delay;
   uint32_t size_k;
   uint32_t size_delay;
   uint32_t ratio;
};

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

RING_BUFFER usb_buffer_L(SIZE_USB_BUFFER);
RING_BUFFER usb_buffer_R(SIZE_USB_BUFFER);
RING_BUFFER oversampling_buffer_L(SIZE_OUTPUT_BUFFER);
RING_BUFFER oversampling_buffer_R(SIZE_OUTPUT_BUFFER);
RING_BUFFER output_buffer_L(SIZE_OUTPUT_BUFFER);
RING_BUFFER output_buffer_R(SIZE_OUTPUT_BUFFER);

FIR_FILTER FIR4x0(size_coef_fir_filter_4x_0, RATIO_UPSAMPLING0, coef_fir_filter_4x_0);
IIR_FILTER IIR2x2(size_coef_bq_filter_2x_2, RATIO_UPSAMPLING1, &coef_bq_filter_2x_2[0][0]);
IIR_FILTER IIR4x3(size_coef_bq_filter_4x_3, RATIO_UPSAMPLING1, &coef_bq_filter_4x_3[0][0]);

static unsigned char clock_old = 0;
static unsigned char push_buffer_old = 0;
static uint32_t prescale_counter = 0;
static bool can_output = false;
static bool can_write_usb_buffer = false;
static uint32_t prescale_counter2 = 0;

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

   // scheduler
   if (clock == 1 && clock_old == 0)
   {
      can_output = true; // 出力タイミング制御用変数

      // ここで分周を行っています
      if (prescale_counter >= RATIO_UPSAMPLING)
      {
         can_write_usb_buffer = true; // 入力リングバッファへのサンプルホールドタイミング制御用変数です
         prescale_counter = 0;        // 分周カウンタ値を初期化して繰り返します
      }
      prescale_counter++; // 分周カウンタを増分します
   }
   clock_old = clock; // クロックの前回値を保存します

   // input buffer
   if (can_write_usb_buffer)
   {
      int16_t is_buffer_full_L = 0; // 入力リングバッファがフルでないことを確認するためのもの(デバッグ用)
      int16_t is_buffer_full_R = 0; // 入力リングバッファがフルでないことを確認するためのもの(デバッグ用)

      is_buffer_full_L |= usb_buffer_L.write(((int32_t)(signal_in0 * GAIN_ANTICLIPPING)) << 16); // ここでバッファに入力データを格納する
      is_buffer_full_R |= usb_buffer_R.write(((int32_t)(signal_in1 * GAIN_ANTICLIPPING)) << 16); // ここでバッファに入力データを格納する
      // debug1 = is_buffer_full_L;
      can_write_usb_buffer = false; // 立てたフラグを解除する
   }

   // upsampling and cueue output buffer
   // push_buffer信号に同期して実行される
   if (push_buffer == 1 && push_buffer_old == 0)
   {
      // decueue input ringbuffer バッファからデータを読み込む
      uint32_t length = usb_buffer_L.get_size(); // 入力バッファに格納されたデータ量を取得する
      debug1 = length;
      int32_t *usb_dequeue_buffer_L = new int32_t[length];   // バッファから取り出すデータの仮保存先(配列)を割り当てる
      int32_t *usb_dequeue_buffer_R = new int32_t[length];   // バッファから取り出すデータの仮保存先(配列)を割り当てる
      usb_buffer_L.read_array(usb_dequeue_buffer_L, length); // バッファから仮保存先の配列にデータを読み込む
      usb_buffer_R.read_array(usb_dequeue_buffer_R, length); // バッファから仮保存先の配列にデータを読み込む

      float* buffer_inL_float = new float[length];
      float* buffer_inR_float = new float[length];
      int32_to_float_array(usb_dequeue_buffer_L, buffer_inL_float, length);
      int32_to_float_array(usb_dequeue_buffer_R, buffer_inR_float, length);

      // Prepareing buffers アップサンプリング処理の一時データ保存先を作る
      float *upsampling_buffer_L0 = new float[length * RATIO_UPSAMPLING];
      float *upsampling_buffer_L1 = new float[length * RATIO_UPSAMPLING];
      float *upsampling_buffer_R0 = new float[length * RATIO_UPSAMPLING];
      float *upsampling_buffer_R1 = new float[length * RATIO_UPSAMPLING];

      // アンチクリッピングゲインを乗じる
      f32_scale_array(buffer_inL_float, upsampling_buffer_L0, GAIN_ANTICLIPPING, length);
      f32_scale_array(buffer_inR_float, upsampling_buffer_R0, GAIN_ANTICLIPPING, length);

      // upsampling0 : 44.1kHz to 176.4kHz FIR
      uint32_t len_L = FIR4x0.interporate(length, upsampling_buffer_L0, upsampling_buffer_L1);
      uint32_t len_R = FIR4x0.interporate(length, upsampling_buffer_R0, upsampling_buffer_R1);

      // upsampling1 : 176.4kHz to 352.8kHz IIR
      len_L = IIR2x2.interporate(len_L, upsampling_buffer_L1, upsampling_buffer_L0);
      len_R = IIR2x2.interporate(len_R, upsampling_buffer_R1, upsampling_buffer_R0);

      // upsampling2 : 352.8kHz to 1411.2kHz IIR
      len_L = IIR4x3.interporate(len_L, upsampling_buffer_L0, upsampling_buffer_L1);
      len_R = IIR4x3.interporate(len_R, upsampling_buffer_R0, upsampling_buffer_R1);

      // floatをint32にキャスト
      int32_t* out_buf_L = new int32_t[len_L];
      int32_t* out_buf_R = new int32_t[len_R];
      float_to_int32_array(upsampling_buffer_L1, out_buf_L, len_L);
      float_to_int32_array(upsampling_buffer_R1, out_buf_R, len_R);

      // packing output buffer 出力バッファに書き込む
      output_buffer_L.write_array(out_buf_L, len_L);
      output_buffer_R.write_array(out_buf_R, len_R);

      // メモリを解放
      delete[] usb_dequeue_buffer_L;
      delete[] usb_dequeue_buffer_R;
      delete[] buffer_inL_float;
      delete[] buffer_inR_float;
      delete[] upsampling_buffer_L0;
      delete[] upsampling_buffer_L1;
      delete[] upsampling_buffer_R0;
      delete[] upsampling_buffer_R1;
      delete[] out_buf_L;
      delete[] out_buf_R;
   }
   push_buffer_old = push_buffer; // push_bufferの前回値を更新

   // output
   // clockに同期して出力処理が実行される
   if (can_output)
   {
      if (output_buffer_L.get_size() > 0)
      {
         int32_t out_buffer = 0; // 出力データの読み出し先の一時変数

         // Lchの出力データをバッファから読み込む
         output_buffer_L.read(&out_buffer);
         output0 = (double)out_buffer;

         // Rchの出力データをバッファから読み込む
         output_buffer_R.read(&out_buffer);
         output1 = (double)out_buffer;
      }
      can_output = false; // フラグを下す
   }
}
