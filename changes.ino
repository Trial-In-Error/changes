#include <MicroView.h>
#include <avr/pgmspace.h>

uint8_t settings[8] = {7, 23, 6, 4, 16, 3, 3, 4};
uint8_t verticalOffset;
uint8_t horizontalOffset;
uint8_t halfWidth;
uint8_t gapWidth;
uint8_t fullWidth;
uint8_t gapHeight;
uint8_t height;
uint8_t seperatorHeight;

uint8_t hexagramList[64][6];
uint8_t globalCounter = 0;


prog_char string_0[] PROGMEM = "Force";
prog_char string_1[] PROGMEM = "Field";
prog_char string_2[] PROGMEM = "Sprouting";
prog_char string_3[] PROGMEM = "Enveloping";
prog_char string_4[] PROGMEM = "Attending";
prog_char string_5[] PROGMEM = "Arguing";
prog_char string_6[] PROGMEM = "Leading";
prog_char string_7[] PROGMEM = "Grouping";
prog_char string_8[] PROGMEM = "Small Accumulating";
prog_char string_9[] PROGMEM = "Treading";
prog_char string_10[] PROGMEM = "Pervading";
prog_char string_11[] PROGMEM = "Obstruction";
prog_char string_12[] PROGMEM = "Concording People";
prog_char string_13[] PROGMEM = "Great Possessing";
prog_char string_14[] PROGMEM = "Humbling";
prog_char string_15[] PROGMEM = "Providing-For";
prog_char string_16[] PROGMEM = "Following";
prog_char string_17[] PROGMEM = "Correcting";
prog_char string_18[] PROGMEM = "Nearing";
prog_char string_19[] PROGMEM = "Viewing";
prog_char string_20[] PROGMEM = "Gnawing Bite";
prog_char string_21[] PROGMEM = "Adorning";
prog_char string_22[] PROGMEM = "Stripping";
prog_char string_23[] PROGMEM = "Returning";
prog_char string_24[] PROGMEM = "Without Embroiling";
prog_char string_25[] PROGMEM = "Great Accumulating";
prog_char string_26[] PROGMEM = "Swallowing";
prog_char string_27[] PROGMEM = "Great Exceeding";
prog_char string_28[] PROGMEM = "Gorge";
prog_char string_29[] PROGMEM = "Radiance";
prog_char string_30[] PROGMEM = "Conjoining";
prog_char string_31[] PROGMEM = "Persevering";
prog_char string_32[] PROGMEM = "Retiring";
prog_char string_33[] PROGMEM = "Great Invigorating";
prog_char string_34[] PROGMEM = "Prospering";
prog_char string_35[] PROGMEM = "Darkening of the Light";
prog_char string_36[] PROGMEM = "Dwelling People";
prog_char string_37[] PROGMEM = "Polarising";
prog_char string_38[] PROGMEM = "Limping";
prog_char string_39[] PROGMEM = "Taking-Apart";
prog_char string_40[] PROGMEM = "Diminishing";
prog_char string_41[] PROGMEM = "Augmenting";
prog_char string_42[] PROGMEM = "Displacement";
prog_char string_43[] PROGMEM = "Coupling";
prog_char string_44[] PROGMEM = "Clustering";
prog_char string_45[] PROGMEM = "Ascending";
prog_char string_46[] PROGMEM = "Confining";
prog_char string_47[] PROGMEM = "Welling";
prog_char string_48[] PROGMEM = "Skinning";
prog_char string_49[] PROGMEM = "Holding";
prog_char string_50[] PROGMEM = "Shake";
prog_char string_51[] PROGMEM = "Bound";
prog_char string_52[] PROGMEM = "Infiltrating";
prog_char string_53[] PROGMEM = "Converting the Maiden";
prog_char string_54[] PROGMEM = "Abounding";
prog_char string_55[] PROGMEM = "Sojourning";
prog_char string_56[] PROGMEM = "Ground";
prog_char string_57[] PROGMEM = "Open";
prog_char string_58[] PROGMEM = "Dispersing";
prog_char string_59[] PROGMEM = "Articulating";
prog_char string_60[] PROGMEM = "Center Returning";
prog_char string_61[] PROGMEM = "Small Exceeding";
prog_char string_62[] PROGMEM = "Already Fording";
prog_char string_63[] PROGMEM = "Not Yet Fording";


// Then set up a table to refer to your strings.
PROGMEM const char *hexagramNames[] =     // change "string_table" name to suit
{   
  string_0,
  string_1,
  string_2,
  string_3,
  string_4,
  string_5,
  string_6,
  string_7,
  string_8,
  string_9,
  string_10,
  string_11,
  string_12,
  string_13,
  string_14,
  string_15,
  string_16,
  string_17,
  string_18,
  string_19,
  string_20,
  string_21,
  string_22,
  string_23,
  string_24,
  string_25,
  string_26,
  string_27,
  string_28,
  string_29,
  string_30,
  string_31,
  string_32,
  string_33,
  string_34,
  string_35,
  string_36,
  string_37,
  string_38,
  string_39,
  string_40,
  string_41,
  string_42,
  string_43,
  string_44,
  string_45,
  string_46,
  string_47,
  string_48,
  string_49,
  string_50,
  string_51,
  string_52,
  string_53,
  string_54,
  string_55,
  string_56,
  string_57,
  string_58,
  string_59,
  string_60,
  string_61,
  string_62,
  string_63
};

char buffer[30];    // make sure this is large enough for the largest string it must hold

void drawHexagram(uint8_t hexagram[]) {
  uView.clear(PAGE);
  for(uint8_t count = 0; count < 6; count++) {
    if(hexagram[count] == 0) {
          // if this line is split
          uView.rectFill( verticalOffset + count*height + count*seperatorHeight,
                    horizontalOffset, height, halfWidth);
          uView.rectFill( verticalOffset + count*height + count*seperatorHeight,
                    horizontalOffset + halfWidth + gapWidth, height, halfWidth);
    } else {
          // if this line is solid
          uView.rectFill( verticalOffset + count*height + count*seperatorHeight,
                    horizontalOffset, height, fullWidth);
    }
  }
  uView.display();
}

void drawHexagramRotated(uint8_t hexagram[]) {
  uView.clear(PAGE);
  for(uint8_t count = 0; count < 6; count++) {
    if(hexagram[count] == 0) {
          // if this line is split
          uView.rectFill( horizontalOffset, 
                    verticalOffset + count*height + count*seperatorHeight,  halfWidth,height );
          uView.rectFill( horizontalOffset + halfWidth + gapWidth,
                    verticalOffset + count*height + count*seperatorHeight, halfWidth, height );
    } else {
          // if this line is solid
          uView.rectFill( horizontalOffset,
                    verticalOffset + count*height + count*seperatorHeight, fullWidth, height );
    }
  }
  uView.display();
}

void hexSetup() {

  //Hexagram 1 is named 乾 (qián), "Force". Other variations include "the creative", "strong action", "the key",  and "god".
  //Its inner (lower) trigram is ☰ (乾 qián) force = 天 heaven, and its outer (upper) trigram is the same.
  uint8_t temp0[6] = {1, 1, 1, 1, 1, 1};
  memcpy(hexagramList[0], temp0, sizeof(hexagramList[0]));

  //Hexagram 2 is named 坤 (kūn), "Field". Other variations include "the receptive", "acquiescence", and "the flow".
  //Its inner trigram is ☷ (坤 kūn) field = 地 earth, and its outer trigram is identical.
  uint8_t temp1[6] = {0, 0, 0, 0, 0, 0};
  memcpy(hexagramList[1], temp1, sizeof(hexagramList[1]));

  //Hexagram 3 is named 屯 (zhūn), "Sprouting". Other variations include "difficulty at the beginning", "gathering support", and "hoarding".
  //Its inner trigram is  ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water.
  uint8_t temp2[6] = {0, 1, 0, 0, 0, 1};
  memcpy(hexagramList[2], temp2, sizeof(hexagramList[2]));

  //Hexagram 4 is named 蒙 (méng), "Enveloping". Other variations include "youthful folly", "the young shoot", and "discovering".
  //Its inner trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water. Its outer trigram is ☶ (艮 gèn) bound = 山 mountain.
  uint8_t temp3[6] = {1, 0, 0, 0, 1, 0};
  memcpy(hexagramList[3], temp3, sizeof(hexagramList[3]));

  //Hexagram 5 is named 需 (xū), "Attending". Other variations include "waiting", "moistened", and "arriving".
  //Its inner trigram is  ☰ (乾 qián) force = 天 heaven, and its outer trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water.
  uint8_t temp4[6] = {0, 1, 0, 1, 1, 1};
  memcpy(hexagramList[4], temp4, sizeof(hexagramList[4]));

  //Hexagram 6 is named 訟 (sòng), "Arguing". Other variations include "conflict" and "lawsuit".
  //Its inner trigram is  ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water, and its outer trigram is ☰ (乾 qián) force = 天 heaven.
  uint8_t temp5[6] = {1, 1, 1, 0, 1, 0};
  memcpy(hexagramList[5], temp5, sizeof(hexagramList[5]));

  //Hexagram 7 is named 師 (shī), "Leading". Other variations include "the army" and "the troops".
  //Its inner trigram is  ☵ (坎 kǎn) gorge = 水 water, and its outer trigram is ☷ (坤 kūn) field = 地 earth.
  uint8_t temp6[6] = {0, 0, 0, 0, 1, 0};
  memcpy(hexagramList[6], temp6, sizeof(hexagramList[6]));

  //Hexagram 8 is named 比 (bǐ), "Grouping". Other variations include "holding together" and "alliance".
  //Its inner trigram is  ☷ (坤 kūn) field = 地 earth, and its outer trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water.
  uint8_t temp7[6] = {0, 1, 0, 0, 0, 0};
  memcpy(hexagramList[7], temp7, sizeof(hexagramList[7]));

  //Hexagram 9 is named 小畜 (xiǎo chù), "Small Accumulating". Other variations include "the taming power of the small" and "small harvest".
  //Its inner trigram is  ☰ (乾 qián) force = 天 heaven, and its outer trigram is ☴ (巽 xùn) ground = 風 wind.
  uint8_t temp8[6] = {1, 1, 0, 1, 1, 1};
  memcpy(hexagramList[8], temp8, sizeof(hexagramList[8]));

  //Hexagram 10 is named 履 (lǚ), "Treading". Other variations include "treading (conduct)" and "continuing".
  //Its inner trigram is  ☱ (兌 duì) open = 澤 swamp, and its outer trigram is ☰ (乾 qián) force = 天 heaven.
  uint8_t temp9[6] = {1, 1, 1, 0, 1, 1};
  memcpy(hexagramList[9], temp9, sizeof(hexagramList[9]));

  //Hexagram 11 is named 泰 (tài), "Pervading". Other variations include "peace" and "greatness".
  //Its inner trigram is ☰ (乾 qián) force = 天 heaven, and its outer trigram is ☷ (坤 kūn) field = 地 earth.
  uint8_t temp10[6] = {0, 0, 0, 1, 1, 1};
  memcpy(hexagramList[10], temp10, sizeof(hexagramList[10]));

  //Hexagram 12 is named 否 (pǐ), "Obstruction". Other variations include "standstill (stagnation)" and "selfish persons".
  //Its inner trigram is ☷ (坤 kūn) field = 地 earth, and its outer trigram is ☰ (乾 qián) force = 天 heaven.
  uint8_t temp11[6] = {1, 1, 1, 0, 0, 0};
  memcpy(hexagramList[11], temp11, sizeof(hexagramList[11]));
  
  //Hexagram 13 is named 同人 (tóng rén), "Concording People". Other variations include "fellowship with men" and "gathering men".
  //Its inner trigram is ☲ (離 lí) radiance = Fire (Wu Xing)|火 fire, and its outer trigram is ☰ (乾 qián) force = 天 heaven.
  uint8_t temp12[6] = {1, 1, 1, 1, 0, 1};
  memcpy(hexagramList[12], temp12, sizeof(hexagramList[12]));
  
  //Hexagram 14 is named 大有 (dà yǒu), "Great Possessing". Other variations include "possession in great measure" and "the great possession".
  //Its inner trigram is ☰ (乾 qián) force = 天 heaven, and its outer trigram is ☲ (離 lí) radiance = Fire (Wu Xing)|火 fire.
  uint8_t temp13[6] = {1, 0, 1, 1, 1, 1};
  memcpy(hexagramList[13], temp13, sizeof(hexagramList[13]));
  
  //Hexagram 15 is named 謙 (qiān), "Humbling". Other variations include "modesty".
  //Its inner trigram is ☶ (艮 gèn) bound = 山 mountain and its outer trigram is  ☷ (坤 kūn) field = 地 earth.
  uint8_t temp14[6] = {0, 0, 0, 1, 0, 0};
  memcpy(hexagramList[14], temp14, sizeof(hexagramList[14]));
  
  //Hexagram 16 is named 豫 (yù), "Providing-For". Other variations include "enthusiasm" and "excess".
  //Its inner trigram is  ☷ (坤 kūn) field = 地 earth, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp15[6] = {0, 0, 0, 1, 1, 1};
  memcpy(hexagramList[15], temp15, sizeof(hexagramList[15]));
  
  //Hexagram 17 is named 隨 (suí), "Following".
  //Its inner trigram is  ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☱ (兌 duì) open = 澤|澤 swamp.
  uint8_t temp16[6] = {0, 1, 1, 0, 0, 1};
  memcpy(hexagramList[16], temp16, sizeof(hexagramList[16]));
  
  //Hexagram 18 is named '蠱' (gŭ), "Correcting". Other variations include "work on what has been spoiled (decay)", decaying and "branch".
  //Its inner trigram is  ☴ (巽 xùn) ground = 風 wind, and its outer trigram is ☶ (艮 gèn) bound = 山 mountain. Gu (poison) is the name of a venom-based poison traditionally used in Chinese witchcraft.
  uint8_t temp17[6] = {1, 0, 0, 1, 1, 0};
  memcpy(hexagramList[17], temp17, sizeof(hexagramList[17]));
  
  //Hexagram 19 is named 臨 (lín), "Nearing". Other variations include "approach" and "the forest".
  //Its inner trigram is ☱ (兌 duì) open = (澤) swamp, and its outer trigram is ☷ (坤 kūn) field = (地) earth.
  uint8_t temp18[6] = {0, 0, 0, 0, 1, 1};
  memcpy(hexagramList[18], temp18, sizeof(hexagramList[18]));
  
  //Hexagram 20 is named 觀 (guān), "Viewing". Other variations include "contemplation (view)" and "looking up".
  //Its inner trigram is ☷ (坤 kūn) field = 地 earth, and its outer trigram is ☴ (巽 xùn) ground = 風 wind.
  uint8_t temp19[6] = {1, 1, 0, 0, 0, 0};
  memcpy(hexagramList[19], temp19, sizeof(hexagramList[19]));
  
  //Hexagram 21 is named 噬嗑 (shì kè), "Gnawing Bite". Other variations include "biting through" and "biting and chewing".
  //Its inner trigram is ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☲ (離 lí) radiance = Fire (Wu Xing)|火 fire.
  uint8_t temp20[6] = {1, 0, 1, 0, 0, 1};
  memcpy(hexagramList[20], temp20, sizeof(hexagramList[20]));
  
  //Hexagram 22 is named 賁 (bì), "Adorning". Other variations include "grace" and "luxuriance".
  //Its inner trigram is ☲ (離 lí) radiance = (火) fire, and its outer trigram is ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp21[6] = {1, 0, 0, 1, 0, 1};
  memcpy(hexagramList[21], temp21, sizeof(hexagramList[21]));
  
  //Hexagram 23 is named 剝 (bō), "Stripping". Other variations include "splitting apart" and "flaying".
  //Its inner trigram is ☷ (坤 kūn) field = (地) earth, and its outer trigram is ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp22[6] = {1, 0, 0, 0, 0, 0,};
  memcpy(hexagramList[22], temp22, sizeof(hexagramList[22]));
  
  //Hexagram 24 is named 復 (fù), "Returning". Other variations include "return (the turning point)".
  //Its inner trigram is ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☷ (坤 kūn) field = 地 earth.
  uint8_t temp23[6] = {0, 0, 0, 1, 1, 1};
  memcpy(hexagramList[23], temp23, sizeof(hexagramList[23]));
  
  //Hexagram 25 is named 無妄 (wú wàng), "Without Embroiling". Other variations include "innocence (the unexpected)" and "pestilence".
  //Its inner trigram is ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☰ (乾 qián) force = 天 heaven.
  uint8_t temp24[6] = {1, 1, 1, 0, 0, 1};
  memcpy(hexagramList[24], temp24, sizeof(hexagramList[24]));
  
  //Hexagram 26 is named 大畜 (dà chù), "Great Accumulating". Other variations include "the taming power of the great", "great storage", and "potential energy."
  //Its inner trigram is ☰ (乾 qián) force = (天) heaven, and its outer trigram is ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp25[6] = {1, 0, 0, 1, 1, 1};
  memcpy(hexagramList[25], temp25, sizeof(hexagramList[25]));
  
  //Hexagram 27 is named 頤 (yí), "Swallowing". Other variations include "the corners of the mouth (providing nourishment)", "jaws" and "comfort/security".
  //Its inner trigram is ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp26[6] = {1, 0, 0, 0, 0, 1};
  memcpy(hexagramList[26], temp26, sizeof(hexagramList[26]));
  
  //Hexagram 28 is named 大過 (dà guò), "Great Exceeding". Other variations include "preponderance of the great", "great surpassing" and "critical mass."
  //Its inner trigram is ☴ (巽 xùn) ground = (風) wind, and its outer trigram is  ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp27[6] = {0, 1, 1, 1, 1, 0};
  memcpy(hexagramList[27], temp27, sizeof(hexagramList[27]));
  
  //Hexagram 29 is named 坎 (kǎn), "Gorge". Other variations include "the abysmal (water)" and "repeated entrapment".
  //Its inner trigram is ☵ (坎 kǎn) gorge = (水) water, and its outer trigram is  identical.
  uint8_t temp28[6] = {0, 1, 0, 0, 1, 0};
  memcpy(hexagramList[28], temp28, sizeof(hexagramList[28]));
  
  //Hexagram 30 is named 離 (lí), "Radiance". Other variations include "the clinging, fire" and "the net".
  //Its inner trigram is ☲ (離 lí) radiance = (火) fire, and its outer trigram is  identical. The origin of the character has its roots in symbols of long-tailed birds such as the peacock or the legendary phoenix.
  uint8_t temp29[6] = {1, 0, 1, 1, 0, 1};
  memcpy(hexagramList[29], temp29, sizeof(hexagramList[29]));
  
  //Hexagram 31 is named 咸 (xián), "Conjoining". Other variations include "influence (wooing)" and "feelings".
  //Its inner trigram is ☶ (艮 gèn) bound = (山) mountain, and its outer trigram is  ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp30[6] = {0, 1, 1, 1, 0, 0};
  memcpy(hexagramList[30], temp30, sizeof(hexagramList[30]));
  
  //Hexagram 32 is named 恆 (héng), "Persevering". Other variations include "duration" and "constancy".
  //Its inner trigram is ☴ (巽 xùn) ground = 風 wind, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp31[6] = {0, 0, 1, 1, 1, 0};
  memcpy(hexagramList[31], temp31, sizeof(hexagramList[31]));
  
  //Hexagram 33 is named 遯 (dùn), "Retiring". Other variations include "retreat" and "yielding".
  //Its inner trigram is ☶ (艮 gèn) bound = (山) mountain, and its outer trigram is ☰ (乾 qián) force = (天) heaven.
  uint8_t temp32[6] = {1, 1, 1, 1, 0, 0};
  memcpy(hexagramList[32], temp32, sizeof(hexagramList[32]));
  
  //Hexagram 34 is named 大壯 (dà zhuàng), "Great Invigorating". Other variations include "the power of the great" and "great maturity".
  //Its inner trigram is ☰ (乾 qián) force = (天) heaven, and its outer trigram is ☳ (震 zhèn) shake = (雷) thunder.
  uint8_t temp33[6] = {0, 1, 1, 1, 0, 0};
  memcpy(hexagramList[33], temp33, sizeof(hexagramList[33]));
  
  //Hexagram 35 is named 晉 (jìn), "Prospering". Other variations include "progress" and "aquas".
  //Its inner trigram is ☷ (坤 kūn) field = (地) earth, and its outer trigram is ☲ (離 lí) radiance = (火) fire.
  uint8_t temp34[6] = {1, 0, 1, 0, 0, 0};
  memcpy(hexagramList[34], temp34, sizeof(hexagramList[34]));
  
  //Hexagram 36 is named 明夷 (míng yí), “Darkening of the Light.” Other variations are "brilliance injured" and "intelligence hidden".
  //Its inner trigram is ☲ (離 lí) radiance = (火) fire, and its outer trigram is ☷ (坤 kūn) field = (地) earth.
  uint8_t temp35[6] = {0, 0, 0, 1, 0, 1};
  memcpy(hexagramList[35], temp35, sizeof(hexagramList[35]));
  
  //Hexagram 37 is named 家人 (jiā rén), "Dwelling People". Other variations include "the family (the clan)" and "family members".
  //Its inner trigram is ☲ (離 lí) radiance = (火) fire, and its outer trigram is ☴ (巽 xùn) ground = (風) wind.
  uint8_t temp36[6] = {1, 1, 0, 1, 0, 1};
  memcpy(hexagramList[36], temp36, sizeof(hexagramList[36]));
  
  //Hexagram 38 is named 睽 (kuí), "Polarising". Other variations include "opposition" and "perversion".
  //Its inner trigram is ☱ (兌 duì) open = (澤) swamp, and its outer trigram is ☲ (離 lí) radiance = (火) fire.
  uint8_t temp37[6] = {1, 0, 1, 0, 1, 1};
  memcpy(hexagramList[37], temp37, sizeof(hexagramList[37]));
  
  //Hexagram 39 is named 蹇 (jiǎn), "Limping". Other variations include "obstruction" and "afoot".
  //Its inner trigram is ☶ (艮 gèn) bound = (山) mountain, and its outer trigram is ☵ (坎 kǎn) gorge = (水) water.
  uint8_t temp38[6] = {0, 1, 0, 1, 0, 0};
  memcpy(hexagramList[38], temp38, sizeof(hexagramList[38]));
  
  //Hexagram 40 is named 解 (xiè), "Taking-Apart". Other variations include "deliverance" and "untangled".
  //Its inner trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp39[6] = {0, 0, 1, 0, 1, 0};
  memcpy(hexagramList[39], temp39, sizeof(hexagramList[39]));
  
  //Hexagram 41 is named 損 (sǔn), "Diminishing". Other variations include "decrease".
  //Its inner trigram is ☱ (兌 duì) open = (澤) swamp, and its outer trigram is ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp40[6] = {1, 0, 0, 0, 1, 1};
  memcpy(hexagramList[40], temp40, sizeof(hexagramList[40]));
  
  //Hexagram 42 is named 益 (yì), "Augmenting". Other variations include "increase".
  //Its inner trigram is ☳ (震 zhèn) shake = 雷|雷 thunder, and its outer trigram is ☴ (巽 xùn) ground = 風 wind.
  uint8_t temp41[6] = {1, 1, 0, 0, 0, 1};
  memcpy(hexagramList[41], temp41, sizeof(hexagramList[41]));
  
  //Hexagram 43 is named 夬 (guài), "Displacement". Other variations include "resoluteness", "parting", and "break-through".
  //Its inner trigram is ☰ (乾 qián) force = (天) heaven, and its outer trigram is ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp42[6] = {0, 1, 1, 1, 1, 1};
  memcpy(hexagramList[42], temp42, sizeof(hexagramList[42]));
  
  //Hexagram 44 is named 姤 (gòu), "Coupling". Other variations include "coming to meet" and "meeting".
  //Its inner trigram is ☴ (巽 xùn) ground = (風) wind, and its outer trigram is ☰ (乾 qián) force = (天) heaven.
  uint8_t temp43[6] = {1, 1, 1, 1, 1, 0};
  memcpy(hexagramList[43], temp43, sizeof(hexagramList[43]));
  
  //Hexagram 45 is named 萃 (cuì), "Clustering". Other variations include "gathering together (massing)" and "finished".
  //Its inner trigram is ☷ (坤 kūn) field = (地) earth, and its outer trigram is ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp44[6] = {0, 1, 1, 0, 0, 0};
  memcpy(hexagramList[44], temp44, sizeof(hexagramList[44]));
  
  //Hexagram 46 is named 升 (shēng), "Ascending". Other variations include "pushing upward".
  //Its inner trigram is ☴ (巽 xùn) ground = (風) wind, and its outer trigram is ☷ (坤 kūn) field = (地) earth.
  uint8_t temp45[6] = {0, 0, 0, 1, 1, 0};
  memcpy(hexagramList[45], temp45, sizeof(hexagramList[45]));
  
  //Hexagram 47 is named 困 (kùn), "Confining". Other variations include "oppression (exhaustion)" and "entangled".
  //Its inner trigram is ☵ (坎 kǎn) gorge = (水) water, and its outer trigram is ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp46[6] = {0, 1, 1, 0, 1, 0};
  memcpy(hexagramList[46], temp46, sizeof(hexagramList[46]));
  
  //Hexagram 48 is named 井 (jǐng), "Welling". Other variations include "the well".
  //Its inner trigram is ☴ (巽 xùn) ground = (風) wind, and its outer trigram is ☵ (坎 kǎn) gorge = (水) water.
  uint8_t temp47[6] = {0, 1, 0, 1, 1, 0};
  memcpy(hexagramList[47], temp47, sizeof(hexagramList[47]));
  
  //Hexagram 49 is named 革 (gé), "Skinning". Other variations including "revolution (molting)" and "the bridle".
  //Its inner trigram is ☲ (離 lí) radiance = (火) fire, and its outer trigram is ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp48[6] = {0, 1, 1, 1, 0, 1};
  memcpy(hexagramList[48], temp48, sizeof(hexagramList[48]));
  
  //Hexagram 50 is named 鼎 (dǐng), "Holding". Other variations include "the cauldron".
  //Its inner trigram is ☴ (巽 xùn) ground = (風) wind, and its outer trigram is ☲ (離 lí) radiance = (火) fire.
  uint8_t temp49[6] = {1, 0, 1, 1, 1, 0};
  memcpy(hexagramList[49], temp49, sizeof(hexagramList[49]));
  
  //Hexagram 51 is named 震 (zhèn), "Shake". Other variations include "the arousing (shock, thunder)" and "thunder".
  //Both its inner and outer trigrams are ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp50[6] = {0, 0, 1, 0, 0, 1};
  memcpy(hexagramList[50], temp50, sizeof(hexagramList[50]));
  
  //Hexagram 52 is named 艮 (gèn), "Bound". Other variations include "keeping still, mountain" and "stilling".
  //Both its inner and outer trigrams are ☶ (艮 gèn) bound = (山) mountain.
  uint8_t temp51[6] = {1, 0, 0, 1, 0, 0};
  memcpy(hexagramList[51], temp51, sizeof(hexagramList[51]));
  
  //Hexagram 53 is named 漸 (jiàn), "Infiltrating". Other variations include "development (gradual progress)" and "advancement".
  //Its inner trigram is ☶ (艮 gèn) bound = (山) mountain, and its outer trigram is ☴ (巽 xùn) ground = (風) wind.
  uint8_t temp52[6] = {1, 1, 0, 1, 0, 0};
  memcpy(hexagramList[52], temp52, sizeof(hexagramList[52]));
  
  //Hexagram 54 is named 歸妹 (guī mèi), "Converting the Maiden". Other variations include "the marrying maiden" and "returning maiden".
  //Its inner trigram is ☱ (兌 duì) open = (澤) swamp, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp53[6] = {0, 0, 1, 0, 1, 1};
  memcpy(hexagramList[53], temp53, sizeof(hexagramList[53]));
  
  //Hexagram 55 is named 豐 (fēng), "Abounding". Other variations include "abundance" and "fullness".
  //Its inner trigram is ☲ (離 lí) radiance = Water (Wu Xing)|火 fire, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp54[6] = {0, 0, 1, 1, 0, 1};
  memcpy(hexagramList[54], temp54, sizeof(hexagramList[54]));
  
  //Hexagram 56 is named 旅 (lǚ), "Sojourning". Other variations include "the wanderer" and "traveling".
  //Its inner trigram is ☶ (艮 gèn) bound = (山) mountain, and its outer trigram is ☲ (離 lí) radiance = (火) fire.
  uint8_t temp55[6] = {1, 0, 1, 1, 0, 0};
  memcpy(hexagramList[55], temp55, sizeof(hexagramList[55]));
  
  //Hexagram 57 is named 巽 (xùn), "Ground". Other variations include "the gentle (the penetrating, wind)" and "calculations".
  //Both its inner and outer trigrams are ☴ 巽 xùn) ground = 風|風 wind.
  uint8_t temp56[6] = {1, 1, 0, 1, 1, 0};
  memcpy(hexagramList[56], temp56, sizeof(hexagramList[56]));
  
  //Hexagram 58 is named 兌 (duì), "Open". Other variations include "the joyous, lake" and "usurpation".
  //Both its inner and outer trigrams are ☱ (兌 duì) open = (澤) swamp.
  uint8_t temp57[6] = {0, 1, 1, 0, 1, 1};
  memcpy(hexagramList[57], temp57, sizeof(hexagramList[57]));
  
  //Hexagram 59 is named 渙 (huàn), "Dispersing". Other variations include "dispersion (dissolution)" and "dispersal".
  //Its inner trigram is ☵ (坎 kǎn) gorge = (水) water, and its outer trigram is ☴ (巽 xùn) ground = (風) wind.
  uint8_t temp58[6] = {1, 1, 0, 0, 1, 0};
  memcpy(hexagramList[58], temp58, sizeof(hexagramList[58]));
  
  //Hexagram 60 is named 節 (jié), "Articulating". Other variations include "limitation" and "moderation".
  //Its inner trigram is ☱ (兌 duì) open = (澤) swamp, and its outer trigram is ☵ (坎 kǎn) gorge = (水) water.
  uint8_t temp59[6] = {0, 1, 0, 0, 1, 1};
  memcpy(hexagramList[59], temp59, sizeof(hexagramList[59]));
  
  //Hexagram 61 is named 中孚 (zhōng fú), "Center Returning". Other variations include "inner truth" and "central return".
  //Its inner trigram is ☱ (兌 duì) open = 澤|澤 swamp, and its outer trigram is ☴ (巽 xùn) ground = 風 wind.
  uint8_t temp60[6] = {1, 1, 0, 0, 1, 1};
  memcpy(hexagramList[60], temp60, sizeof(hexagramList[60]));
  
  //Hexagram 62 is named 小過 (xiǎo guò), "Small Exceeding". Other variations include "preponderance of the small" and "small surpassing".
  //Its inner trigram is ☶ (艮 gèn) bound = 山 mountain, and its outer trigram is ☳ (震 zhèn) shake = 雷|雷 thunder.
  uint8_t temp61[6] = {0, 0, 1, 1, 0, 0};
  memcpy(hexagramList[61], temp61, sizeof(hexagramList[61]));
  
  //Hexagram 63 is named 既濟 (jì jì), "Already Fording". Other variations include "after completion" and "already completed" or "already done" .
  //Its inner trigram is ☲ (離 lí) radiance = Fire (Wu Xing)|火 fire, and its outer trigram is ☵ (坎 kǎn) gorge = Water (Wu Xing)|水 water.
  uint8_t temp62[6] = {0, 1, 0, 1, 0, 1};
  memcpy(hexagramList[62], temp62, sizeof(hexagramList[62]));
  
  //Hexagram 64 is named 未濟 (wèi jì), "Not Yet Fording". Other variations include "before completion" and "not yet completed".
  //Its inner trigram is ☵ (坎 kǎn) gorge = (水) water, and its outer trigram is ☲ (離 lí) radiance = (火) fire.
  uint8_t temp63[6] = {1, 0, 1, 0, 1, 0};
  memcpy(hexagramList[63], temp63, sizeof(hexagramList[63]));
}

void setup() {
  Serial.begin(9600);
  hexSetup();
  delay(500);
  Serial.print(F("VVVVVVVVVV "));
  for(uint8_t count = 0; count < 6; count++) {
    Serial.print(String(hexagramList[0][count]) + " ");    
  }
  Serial.print(F("^^^^^^^^^^\n"));
  verticalOffset = settings[0];
  horizontalOffset = settings[1];
  halfWidth = settings[2];
  gapWidth = settings[3];
  fullWidth = settings[4];
  gapHeight = settings[5];
  height = settings[6];
  seperatorHeight = settings[7];
  uView.begin();
  uView.clear(PAGE);
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void loop () {
  globalCounter = random(0, 64);
  drawHexagramRotated(hexagramList[globalCounter]);
  strcpy_P(buffer, (char*)pgm_read_word(&(hexagramNames[globalCounter])));
  Serial.print("HexagramList[" + String(globalCounter) + "] " + String(buffer) + ": ");
  for(uint8_t count = 0; count < 6; count++) {
    Serial.print(String(hexagramList[globalCounter][count]) + " ");    
  }
  Serial.print("["+String(freeRam())+"]\n");
  delay(500);
}
