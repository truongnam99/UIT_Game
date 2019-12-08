#include "Aladdin.h"



Aladdin::Aladdin()
{
	GameObject::GameObject();
	this->type = ALADDIN;
	this->health = 8;
	int nx = 1;
	x = 20;
	y = 1050;
	width = 37;
	height = 50;
	currentState = ALADDIN_IDLE1;
	isCollisWithBrick = false;
	time = 0;
	isAttacking = false;
	isJumping = false;
	isClimbing = false;
	isIdle = true;
	isInjured = false;

}


Aladdin::~Aladdin()
{
}

void Aladdin::LoadResource()
{
	Sprites * sprites = Sprites::GetInstance();
	Animations * anim = Animations::GetInstance();
	LPDIRECT3DTEXTURE9 texture = Textures::GetInstance()->Get(ID_TEX_ALADDIN);

	// ALADDIN_IDLE1
	sprites->Add(10101, 9, 128, 46, 178, texture, 0);
	sprites->Add(10102, 56, 131, 97, 178, texture, 3);
	sprites->Add(10103, 107, 126, 147, 178, texture, -2);
	sprites->Add(10104, 157, 123, 201, 178, texture, -5);
	sprites->Add(10105, 211, 126, 251, 178, texture, -2);
	sprites->Add(10106, 261, 127, 302, 178, texture, -1);
	sprites->Add(10107, 313, 127, 355, 178, texture, -1);
	sprites->Add(10108, 365, 125, 409, 178, texture, -3);
	sprites->Add(10109, 419, 127, 461, 178, texture, -1);
	Animation * ani = new Animation(60, 3);
	ani->Add(10101, 2000);
	ani->Add(10102, 60);
	ani->Add(10103, 60);
	ani->Add(10104, 410);
	ani->Add(10105);
	ani->Add(10106,120);
	ani->Add(10107);
	ani->Add(10108, 410);
	ani->Add(10109);
	ani->Add(10106, 120);
	ani->Add(10102);
	ani->Add(10103);
	anim->Add(1, ani);
	this->animations[ALADDIN_IDLE1] = ani;

	// ALADDIN_IDLE2
	sprites->Add(10201, 8, 193, 52, 248, texture, -5);
	sprites->Add(10202, 62, 195, 123, 248, texture, -3);
	sprites->Add(10203, 133, 194, 195, 248, texture, -4);
	sprites->Add(10204, 205, 195, 246, 248, texture, -3);
	sprites->Add(10205, 256, 195, 295, 248, texture, -3);
	sprites->Add(10206, 305, 195, 341, 248, texture, -3);
	sprites->Add(10207, 351, 195, 390, 248, texture, -3);
	sprites->Add(10208, 400, 195, 440, 248, texture, -3);
	sprites->Add(10209, 450, 193, 491, 248, texture, -5);
	sprites->Add(10210, 501, 181, 543, 248, texture, -17);
	sprites->Add(10211, 606, 171, 648, 248, texture, -27);
	sprites->Add(10212, 658, 177, 700, 248, texture, -21);
	sprites->Add(10213, 710, 186, 752, 248, texture, -12);
	sprites->Add(10214, 762, 194, 803, 248, texture, -4);
	sprites->Add(10215, 813, 194, 853, 248, texture, -4);
	sprites->Add(10216, 863, 195, 902, 248, texture, -3);
	sprites->Add(10217, 912, 195, 951, 248, texture, -3);
	ani = new Animation(120);
	ani->Add(10201);
	ani->Add(10202);
	ani->Add(10203);
	ani->Add(10204);
	ani->Add(10205);
	ani->Add(10206);
	ani->Add(10207);
	ani->Add(10208);
	ani->Add(10209);
	ani->Add(10210);
	ani->Add(10211);
	ani->Add(10212);
	ani->Add(10213);
	ani->Add(10214);
	ani->Add(10215);
	ani->Add(10216);
	ani->Add(10217);
	anim->Add(2, ani);
	this->animations[ALADDIN_IDLE2] = ani;

	//ALADDIN_IDLE3
	sprites->Add(10301, 8, 278, 47, 331, texture, -3);
	sprites->Add(10302, 57, 278, 93, 331, texture, -3);
	sprites->Add(10303, 103, 278, 143, 331, texture, -3);
	sprites->Add(10304, 153, 276, 194, 331, texture, -5);
	sprites->Add(10305, 204, 268, 242, 331, texture, -13);
	sprites->Add(10306, 252, 264, 293, 331, texture, -17);
	sprites->Add(10307, 303, 273, 345, 331, texture, -8);
	sprites->Add(10308, 355, 282, 393, 331, texture, 1);
	sprites->Add(10309, 403, 282, 442, 331, texture, 1);
	sprites->Add(10310, 452, 282, 491, 331, texture, 1);
	sprites->Add(10311, 501, 277, 539, 331, texture, -4);
	sprites->Add(10312, 549, 270, 587, 331, texture, -11);
	sprites->Add(10313, 597, 264, 635, 331, texture, -17);
	sprites->Add(10314, 645, 257, 681, 331, texture, -24);
	sprites->Add(10315, 691, 252, 730, 331, texture, -29);
	sprites->Add(10316, 740, 269, 782, 331, texture, -12);
	sprites->Add(10317, 792, 277, 833, 331, texture, -4);
	sprites->Add(10318, 843, 277, 883, 331, texture, -4);
	sprites->Add(10319, 893, 278, 932, 331, texture, -3);
	sprites->Add(10320, 942, 278, 981, 331, texture, -3);
	ani = new Animation(120);
	ani->Add(10301);
	ani->Add(10302);
	ani->Add(10303);
	ani->Add(10304);
	ani->Add(10305);
	ani->Add(10306);
	ani->Add(10307);
	ani->Add(10308);
	ani->Add(10309);
	ani->Add(10310);
	ani->Add(10311);
	ani->Add(10312);
	ani->Add(10313);
	ani->Add(10314);
	ani->Add(10315);
	ani->Add(10316);
	ani->Add(10317);
	ani->Add(10318);
	ani->Add(10319);
	ani->Add(10320);
	anim->Add(3, ani);
	this->animations[ALADDIN_IDLE3] = ani;

	//ALADDIN_IDLE_LOOK_UP
	sprites->Add(10401, 8, 346, 45, 396, texture, 0);
	sprites->Add(10402, 55, 343, 93, 396, texture, -3);
	sprites->Add(10403, 103, 337, 148, 396, texture, -9);
	sprites->Add(10404, 158, 338, 207, 396, texture, -8);
	ani = new Animation(120);
	ani->Add(10401);
	ani->Add(10402);
	ani->Add(10403);
	ani->Add(10404, 10000);
	anim->Add(4, ani);
	this->animations[ALADDIN_IDLE_LOOK_UP] = ani;

	//ALADDIN_IDLE_LOOK_DOWN, ALADDIN_IDLE_SIT
	sprites->Add(10406, 8, 411, 45, 461, texture, 0);
	sprites->Add(10407, 55, 412, 96, 461, texture, 1);
	sprites->Add(10408, 106, 421, 154, 461, texture, 10);
	sprites->Add(10409, 164, 431, 218, 461, texture, 20);
	sprites->Add(10410, 228, 426, 281, 461, texture, 15);
	ani = new Animation(120);
	ani->Add(10406);
	ani->Add(10407);
	ani->Add(10408);
	ani->Add(10409, 1500);
	ani->Add(10410, 10000);
	anim->Add(5, ani);
	this->animations[ALADDIN_IDLE_SIT] = ani;

	// ALADDIN_RUNNING1
	sprites->Add(10701, 8, 504, 45, 554, texture, 0);
	sprites->Add(10702, 55, 506, 95, 554, texture, 2);
	sprites->Add(10703, 105, 503, 148, 554, texture, -1);
	sprites->Add(10704, 158, 496, 213, 554, texture, -8);
	sprites->Add(10705, 223, 499, 278, 554, texture, -5);
	sprites->Add(10706, 288, 497, 332, 554, texture, -7);
	sprites->Add(10707, 342, 501, 383, 554, texture, -3);
	sprites->Add(10708, 393, 497, 434, 554, texture, -7);
	sprites->Add(10709, 444, 497, 496, 554, texture, -7);
	sprites->Add(10710, 506, 500, 552, 554, texture, -4);
	sprites->Add(10711, 562, 496, 604, 554, texture, -8);
	sprites->Add(10712, 614, 502, 655, 554, texture, -2);
	sprites->Add(10713, 665, 500, 699, 554, texture, -4);
	sprites->Add(10714, 709, 497, 758, 554, texture, -7);
	ani = new Animation(120, 5);
	ani->Add(10701);
	ani->Add(10702);
	ani->Add(10703);
	ani->Add(10704);
	ani->Add(10705);
	ani->Add(10706);
	ani->Add(10707);
	ani->Add(10708);
	ani->Add(10709);
	ani->Add(10710);
	ani->Add(10711);
	ani->Add(10712);
	ani->Add(10713);
	ani->Add(10714);
	anim->Add(6, ani);
	this->animations[ALADDIN_RUNNING1] = ani;

	// ALADDIN_RUNNING2
	sprites->Add(10716, 8, 569, 62, 626, texture, -7);
	sprites->Add(10717, 72, 570, 110, 626, texture, -6);
	sprites->Add(10718, 120, 560, 171, 626, texture, -16);
	sprites->Add(10719, 181, 561, 228, 626, texture, -15);
	sprites->Add(10720, 238, 562, 280, 626, texture, -14);
	sprites->Add(10721, 290, 580, 345, 626, texture, 4);
	sprites->Add(10722, 355, 582, 407, 626, texture, 6);
	sprites->Add(10723, 418, 574, 464, 626, texture, -2);
	sprites->Add(10724, 474, 574, 523, 621, texture, 3);
	sprites->Add(10725, 533, 569, 584, 621, texture, -2);
	sprites->Add(10726, 594, 576, 645, 626, texture, 0);
	sprites->Add(10727, 655, 576, 692, 626, texture, 0);
	ani = new Animation(120);
	ani->Add(10716);
	ani->Add(10717);
	ani->Add(10718);
	ani->Add(10719);
	ani->Add(10720);
	ani->Add(10721);
	ani->Add(10722);
	ani->Add(10723);
	ani->Add(10724);
	ani->Add(10725);
	ani->Add(10726);
	ani->Add(10727);
	anim->Add(7, ani);
	this->animations[ALADDIN_RUNNING2] = ani;

	// ALADDIN_PUSHING
	sprites->Add(10729, 8, 657, 45, 707, texture, 0);
	sprites->Add(10730, 55, 661, 111, 707, texture, 4);
	sprites->Add(10731, 121, 663, 186, 707, texture, 6);
	sprites->Add(10732, 196, 662, 266, 707, texture, 5);
	sprites->Add(10733, 276, 663, 353, 707, texture, 6);
	sprites->Add(10734, 363, 663, 435, 707, texture, 6);
	sprites->Add(10735, 445, 663, 511, 707, texture, 6);
	sprites->Add(10736, 521, 663, 596, 707, texture, 6);
	sprites->Add(10737, 606, 663, 687, 707, texture, 6);
	sprites->Add(10738, 697, 663, 772, 707, texture, 6);
	ani = new Animation(120, 3);
	ani->Add(10729);
	ani->Add(10730);
	ani->Add(10731);
	ani->Add(10732);
	ani->Add(10733);
	ani->Add(10734);
	ani->Add(10735);
	ani->Add(10736);
	ani->Add(10737);
	ani->Add(10738);
	anim->Add(8, ani);
	this->animations[ALADDIN_PUSHING] = ani;

	// ALADDIN_JUMPING
	sprites->Add(10901, 8, 754, 45, 804, texture, 0);
	sprites->Add(10902, 55, 757, 96, 804, texture, 3);
	sprites->Add(10903, 106, 760, 165, 804, texture, 6);
	sprites->Add(10904, 175, 742, 227, 804, texture, -12);
	sprites->Add(10905, 237, 743, 291, 804, texture, -11);
	sprites->Add(10906, 301, 735, 355, 804, texture, -19);
	sprites->Add(10907, 365, 730, 416, 804, texture, -24);
	sprites->Add(10908, 426, 738, 464, 804, texture, -16);
	sprites->Add(10909, 474, 741, 510, 804, texture, -13);
	sprites->Add(10910, 520, 725, 555, 804, texture, -29);
	sprites->Add(10911, 565, 711, 599, 804, texture, -43);
	sprites->Add(10912, 609, 719, 659, 804, texture, -35);
	sprites->Add(10913, 669, 760, 728, 804, texture, 6);
	sprites->Add(10914, 738, 754, 775, 804, texture, 0);
	ani = new Animation(120);
	ani->Add(10901,50);
	ani->Add(10902, 50);
	ani->Add(10903, 50);
	ani->Add(10904, 50);
	ani->Add(10905, 50);
	ani->Add(10906, 50);
	ani->Add(10907, 50);
	ani->Add(10908, 50);
	ani->Add(10909, 50);
	ani->Add(10910, 50);
	ani->Add(10911, 50);
	ani->Add(10912, 50);
	ani->Add(10913, 30);
	ani->Add(10914, 30);
	anim->Add(9, ani);
	this->animations[ALADDIN_JUMPING] = ani;

	// ALADDIN_JUMPING_FOWARD
	sprites->Add(10916, 8, 834, 45, 884, texture, 0);
	sprites->Add(10917, 55, 842, 96, 884, texture, 8);
	sprites->Add(10918, 166, 827, 223, 884, texture, -7);
	sprites->Add(10919, 233, 842, 291, 884, texture, 8);
	sprites->Add(10920, 301, 836, 362, 884, texture, 2);
	sprites->Add(10921, 372, 831, 430, 884, texture, -3);
	sprites->Add(10922, 440, 826, 493, 884, texture, -8);
	ani = new Animation(120);
	ani->Add(10916);
	ani->Add(10917);
	ani->Add(10918);
	ani->Add(10919);
	ani->Add(10920);
	ani->Add(10921);
	ani->Add(10922);
	anim->Add(10, ani);
	this->animations[ALADDIN_JUMPING_FOWARD] = ani;

	//ALADDIN_STAYING_ATTACKING
	sprites->Add(11035, 8, 1107, 45, 1157, texture, 0);
	sprites->Add(11036, 55, 1106, 100, 1157, texture, -1);
	sprites->Add(11037, 110, 1095, 161, 1157, texture, -12);
	sprites->Add(11038, 171, 1083, 216, 1157, texture, -24);
	sprites->Add(11039, 226, 1093, 308, 1157, texture, -14);
	sprites->Add(11040, 318, 1104, 369, 1157, texture, -3);
	sprites->Add(11041, 379, 1107, 416, 1157, texture, 0);
	ani = new Animation(120);
	ani->Add(11035);
	ani->Add(11036);
	ani->Add(11037);
	ani->Add(11038);
	ani->Add(11039);
	ani->Add(11040);
	ani->Add(11041);
	this->animations[ALADDIN_STAYING_ATTACKING] = ani;

	//ALADDIN_SITTING_ATTACKING
	sprites->Add(11001, 8, 1172, 55, 1205, texture, 17);
	sprites->Add(11002, 65, 1174, 110, 1205, texture, 19);
	sprites->Add(11003, 120, 1172, 191, 1205, texture, 17);
	sprites->Add(11004, 201, 1171, 293, 1205, texture, 16);
	sprites->Add(11005, 303, 1172, 387, 1205, texture, 17);
	ani = new Animation(120);
	ani->Add(11001);
	ani->Add(11002);
	ani->Add(11003);
	ani->Add(11004);
	ani->Add(11005);
	anim->Add(12, ani);
	this->animations[ALADDIN_SITTING_ATTACKING] = ani;

	// ALADDIN_STAYING_COMBO_ATTACKING
	sprites->Add(11007, 8, 1220, 45, 1270, texture, 0);
	sprites->Add(11008, 55, 1217, 97, 1270, texture, -3);
	sprites->Add(11009, 107, 1210, 145, 1270, texture, -10);
	sprites->Add(11010, 155, 1209, 220, 1270, texture, -11);
	sprites->Add(11011, 230, 1212, 277, 1270, texture, -8);
	sprites->Add(11012, 287, 1216, 334, 1270, texture, -4);
	sprites->Add(11013, 344, 1222, 398, 1270, texture, 2);
	sprites->Add(11014, 408, 1199, 482, 1270, texture, -21);
	sprites->Add(11015, 492, 1184, 546, 1270, texture, -36);
	sprites->Add(11016, 556, 1199, 605, 1270, texture, -21);
	sprites->Add(11017, 615, 1203, 666, 1270, texture, -17);
	ani = new Animation(120);
	ani->Add(11007);
	ani->Add(11008);
	ani->Add(11009);
	ani->Add(11010);
	ani->Add(11011);
	ani->Add(11012);
	ani->Add(11013);
	ani->Add(11014);
	ani->Add(11015);
	ani->Add(11016);
	ani->Add(11017);
	anim->Add(13, ani);
	this->animations[ALADDIN_STAYING_COMBO_ATTACKING] = ani;

	// ALADDIN_RUNING_ATTACKING
	sprites->Add(11019, 8, 1293, 43, 1345, texture, -2);
	sprites->Add(11020, 53, 1285, 104, 1345, texture, -10);
	sprites->Add(11021, 114, 1292, 164, 1345, texture, -3);
	sprites->Add(11022, 174, 1285, 222, 1345, texture, -10);
	sprites->Add(11023, 232, 1290, 305, 1345, texture, -5);
	sprites->Add(11024, 315, 1295, 375, 1345, texture, 0);
	ani = new Animation(120);
	ani->Add(11019);
	ani->Add(11020);
	ani->Add(11021);
	ani->Add(11022);
	ani->Add(11023);
	ani->Add(11024);
	anim->Add(14, ani);
	this->animations[ALADDIN_RUNING_ATTACKING] = ani;

	// ALADDIN_JUMPING_ATTACKING
	sprites->Add(11026, 8, 1360, 60, 1414, texture, -4);
	sprites->Add(11027, 70, 1362, 120, 1414, texture, -2);
	sprites->Add(11028, 130, 1348, 177, 1414, texture, -16);
	sprites->Add(11029, 187, 1358, 239, 1414, texture, -6);
	sprites->Add(11030, 249, 1363, 332, 1414, texture, -1);
	sprites->Add(11031, 342, 1359, 389, 1414, texture, -5);
	sprites->Add(11032, 406, 1356, 459, 1414, texture, -8);
	ani = new Animation(120);
	ani->Add(11026);
	ani->Add(11027);
	ani->Add(11028);
	ani->Add(11029);
	ani->Add(11030);
	ani->Add(11031);
	ani->Add(11032);
	anim->Add(15, ani);
	this->animations[ALADDIN_JUMPING_ATTACKING] = ani;

	//ALADDIN_STAYING_ATTACKING_BY_APPLE
	sprites->Add(11601, 8, 1480, 45, 1530, texture, 0);
	sprites->Add(11602, 55, 1474, 98, 1530, texture, -6);
	sprites->Add(11603, 108, 1471, 149, 1530, texture, -9);
	sprites->Add(11604, 159, 1472, 197, 1530, texture, -8);
	sprites->Add(11605, 207, 1467, 259, 1530, texture, -13);
	sprites->Add(11606, 269, 1470, 315, 1530, texture, -10);
	sprites->Add(11607, 325, 1472, 362, 1530, texture, -8);
	sprites->Add(11608, 372, 1478, 411, 1530, texture, -2);
	ani = new Animation(120);
	ani->Add(11601);
	ani->Add(11602);
	ani->Add(11603);
	ani->Add(11604);
	ani->Add(11605);
	ani->Add(11606);
	ani->Add(11607);
	ani->Add(11608);
	anim->Add(16, ani);
	this->animations[ALADDIN_STAYING_ATTACKING_BY_APPLE] = ani;

	// ALADDIN_SITTING_ATACKING_BY_APPLE
	sprites->Add(11610, 8, 1550, 61, 1585, texture, 15);
	sprites->Add(11611, 71, 1548, 128, 1585, texture, 13);
	sprites->Add(11612, 138, 1541, 175, 1585, texture, 6);
	sprites->Add(11613, 185, 1537, 222, 1585, texture, 2);
	sprites->Add(11614, 232, 1537, 282, 1585, texture, 2);
	sprites->Add(11615, 292, 1548, 374, 1585, texture, 13);
	sprites->Add(11616, 384, 1548, 441, 1585, texture, 13);
	ani = new Animation(120);
	ani->Add(11610);
	ani->Add(11611);
	ani->Add(11612);
	ani->Add(11613);
	ani->Add(11614);
	ani->Add(11615);
	ani->Add(11616);
	anim->Add(17, ani);
	this->animations[ALADDIN_SITTING_ATACKING_BY_APPLE] = ani;

	// ALADDIN_RUNNING_ATTACKING_BY_APPLE
	sprites->Add(11618, 511, 1297, 548, 1352, texture, -5);
	sprites->Add(11619, 572, 1295, 621, 1353, texture, -8);
	sprites->Add(11620, 664, 1297, 713, 1353, texture, -6);
	sprites->Add(11621, 761, 1291, 814, 1353, texture, -12);
	sprites->Add(11622, 849, 1291, 893, 1353, texture, -12);
	sprites->Add(11623, 961, 1301, 996, 1353, texture, -2);
	ani = new Animation(120);
	ani->Add(11618);
	ani->Add(11619);
	ani->Add(11620);
	ani->Add(11621);
	ani->Add(11622);
	ani->Add(11623);
	anim->Add(18, ani);
	this->animations[ALADDIN_RUNNING_ATTACKING_BY_APPLE] = ani;

	// ALADDIN_JUMPING__ATTACKING_BY_APPLE
	sprites->Add(11625, 8, 1600, 57, 1655, texture, -5);
	sprites->Add(11626, 67, 1603, 110, 1655, texture, -2);
	sprites->Add(11627, 120, 1602, 159, 1655, texture, -3);
	sprites->Add(11628, 169, 1600, 224, 1655, texture, -5);
	sprites->Add(11629, 234, 1602, 286, 1655, texture, -3);
	sprites->Add(11630, 296, 1603, 336, 1655, texture, -2);
	sprites->Add(11631, 346, 1602, 404, 1655, texture, -3);
	ani = new Animation(120);
	ani->Add(11625);
	ani->Add(11626);
	ani->Add(11627);
	ani->Add(11628);
	ani->Add(11629);
	ani->Add(11630);
	ani->Add(11631);
	anim->Add(19, ani);
	this->animations[ALADDIN_JUMPING_ATTACKING_BY_APPLE] = ani;

	// ALADDIN_CLIMBING
	sprites->Add(11812, 8, 1697, 40, 1760, texture, -13);
	sprites->Add(11813, 50, 1698, 92, 1760, texture, -12);
	sprites->Add(11814, 102, 1684, 133, 1760, texture, -26);
	sprites->Add(11815, 143, 1679, 171, 1760, texture, -31);
	sprites->Add(11816, 181, 1674, 210, 1760, texture, -36);
	sprites->Add(11817, 220, 1671, 248, 1760, texture, -39);
	sprites->Add(11818, 258, 1681, 286, 1760, texture, -29);
	sprites->Add(11819, 296, 1686, 324, 1760, texture, -24);
	ani = new Animation(120);
	ani->Add(11812);
	ani->Add(11813);
	ani->Add(11814);
	ani->Add(11815);
	ani->Add(11816);
	ani->Add(11817);
	ani->Add(11818);
	ani->Add(11819);
	anim->Add(19, ani);
	this->animations[ALADDIN_CLIMBING] = ani;

	// ALADDIN_FALLING
	sprites->Add(11801, 334, 1687, 368, 1760, texture, -23);
	sprites->Add(11802, 378, 1683, 403, 1760, texture, -27);
	sprites->Add(11803, 413, 1689, 449, 1760, texture, -21);
	sprites->Add(11804, 459, 1696, 507, 1760, texture, -14);
	sprites->Add(11805, 517, 1706, 576, 1760, texture, -4);
	sprites->Add(11806, 586, 1719, 645, 1760, texture, 9);
	sprites->Add(11807, 655, 1706, 707, 1760, texture, -4);
	sprites->Add(11808, 717, 1693, 764, 1760, texture, -17);
	sprites->Add(11809, 774, 1685, 819, 1760, texture, -25);
	ani = new Animation(120);
	ani->Add(11801);
	ani->Add(11802);
	ani->Add(11803);
	ani->Add(11804);
	ani->Add(11805);
	ani->Add(11806);
	ani->Add(11807);
	ani->Add(11808);
	ani->Add(11809);
	anim->Add(21, ani);
	this->animations[ALADDIN_FALLING] = ani;

	// ALADDIN_DAMAGE
	sprites->Add(11801, 8, 2404, 50, 2450, texture, 4);
	sprites->Add(11802, 60, 2398, 115, 2450, texture, -2);
	sprites->Add(11803, 125, 2402, 205, 2450, texture, 2);
	sprites->Add(11804, 215, 2401, 276, 2450, texture, 1);
	sprites->Add(11805, 286, 2400, 345, 2450, texture, 0);
	sprites->Add(11806, 354, 2401, 413, 2450, texture, 1);
	ani = new Animation(120);
	ani->Add(11801);
	ani->Add(11802);
	ani->Add(11803);
	ani->Add(11804);
	ani->Add(11805);
	ani->Add(11806);
	anim->Add(22, ani);
	this->animations[ALADDIN_DAMAGE] = ani;
	// deadth
	// vitory
}

void Aladdin::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = (float)x;
	top = (float)y;
	right = left + (float)width;
	bottom = top + (float)height;
}

void Aladdin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	time += dt;
	vy += ALADDIN_GRAVITY * dt;
	GameObject::Update(dt);
	CollisionWithBrick(coObjects);
	//DebugOut((wchar_t*)L"%f\n", vy);
	int countFrame = animations[currentState]->GetCountFrame(); // Đếm số frame
	int currentFrame = animations[currentState]->GetCurrentFrame();
	if (isAttacking && currentFrame == countFrame - 1)
	{
		isAttacking = false;
		animations[ALADDIN_STAYING_ATTACKING]->SetCurrentFrame(0);
		animations[ALADDIN_SITTING_ATTACKING]->SetCurrentFrame(0);
		animations[ALADDIN_STAYING_COMBO_ATTACKING]->SetCurrentFrame(0);
		animations[ALADDIN_RUNING_ATTACKING]->SetCurrentFrame(0);
		animations[ALADDIN_JUMPING_ATTACKING]->SetCurrentFrame(0);
		animations[ALADDIN_STAYING_ATTACKING_BY_APPLE]->SetCurrentFrame(0);
		animations[ALADDIN_SITTING_ATACKING_BY_APPLE]->SetCurrentFrame(0);
		animations[ALADDIN_RUNNING_ATTACKING_BY_APPLE]->SetCurrentFrame(0);
		animations[ALADDIN_JUMPING_ATTACKING_BY_APPLE]->SetCurrentFrame(0);
	}

}

void Aladdin::Render(int flip)
{
	animations[currentState]->Render(x - Camera::GetInstance()->GetXCam(), y - Camera::GetInstance()->GetYCam(), 255, nx);
	RenderBoundingBox();
}

void Aladdin::SetCurrentState(int state)
{	
	if (currentState == state)
		return;
	

	switch (state)
	{
	case ALADDIN_IDLE1:
		
		if (isAttacking || isJumping || isClimbing|| isInjured)
			break;
		isIdle = true;
		time = 0;
		currentState = state;
		animations[ALADDIN_IDLE1]->SetCurrentFrame(0);
		break;
	case ALADDIN_IDLE2:

		break;
	case ALADDIN_IDLE3:

		break;
	case ALADDIN_IDLE_LOOK_UP:

		break;
	case ALADDIN_IDLE_SIT:

		break;
	case ALADDIN_RUNNING1:
		if (!isJumping && !isClimbing) 
		{
			isRunning = true;
			time = 0;
			currentState = state;
		
		}
		break;
	case ALADDIN_RUNNING2:

		break;
	case ALADDIN_PUSHING:

		break;
	case ALADDIN_JUMPING:
		if (!isJumping) 
		{
			animations[ALADDIN_JUMPING]->SetCurrentFrame(0);
			currentState = state;
			isJumping = true;
			isCollisWithBrick = false;
			
		}
		break;
	case ALADDIN_JUMPING_FOWARD:
		if(!isJumping)
		{
			currentState = state;
			isRunning = true;
			isJumping = true;
			animations[ALADDIN_JUMPING_FOWARD]->SetCurrentFrame(0);
			vy = -ALADIN_JUMP_SPEED;
		}
		
		break;
	case ALADDIN_STAYING_ATTACKING:
		isAttacking = true;
		isIdle = true;
		currentState = state;
		break;
	case ALADDIN_SITTING_ATTACKING:

		break;
	case ALADDIN_STAYING_COMBO_ATTACKING:

		break;
	case ALADDIN_RUNING_ATTACKING:
		isRunning = true;
		isAttacking = true;
		currentState = state;
		break;
	case ALADDIN_JUMPING_ATTACKING:
		isJumping = true;
		isAttacking = true;
		currentState = state;
		break;
	case ALADDIN_STAYING_ATTACKING_BY_APPLE:
		isAttacking = true;
		currentState = state;
		break;
	case ALADDIN_SITTING_ATACKING_BY_APPLE:

		break;
	case ALADDIN_RUNNING_ATTACKING_BY_APPLE:
		isJumping = true;
		isAttacking = true;
		currentState = state;
		break;
	case ALADDIN_JUMPING_ATTACKING_BY_APPLE:

		break;
	case ALADDIN_CLIMBING:

		break;
	case ALADDIN_FALLING:

		break;
	default:
		break;
	}
}

void Aladdin::CollisionWithBrick(vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == oType::BRICK)
		{
			list_Brick.push_back(coObject->at(i));
		}
	}

	CalcPotentialCollisions(&list_Brick, coEvents);
	
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		LPGAMEOBJECT ac = coEvents.at(0)->obj;
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		if (nx != 0) vx = 0;
		//xet logic va cham voi brick
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			LPGAMEOBJECT g=e->obj;

			if (dynamic_cast<Brick *>(e->obj))//e->obj is Brick
			{
				if (e->nx != 0)//co xay ra va cham theo phuong Ox
				{
					x += dx;
					continue;
				}
				else//k xay ra va cham theo phuong Ox
				{
					x += min_tx * dx + nx * 0.4f;
				}

				if (e->ny == -1)//dang di xuong
				{
					y += min_ty * dy + ny * 0.4f;
					if (ny != 0)
					{
						vy = 0;
					}
					isCollisWithBrick = true;
					isJumping = false;
				}
				else// Nhay duoi len(ny==1)
				{
					/*if(e->ny==0)*/
					y += dy;
				}
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

int Aladdin::GetGroupState(int state)
{
	switch (state) {
	case ALADDIN_IDLE1:
	case ALADDIN_IDLE2:
	case ALADDIN_IDLE3:
	case ALADDIN_IDLE_LOOK_UP:
	case ALADDIN_IDLE_SIT:
		return ALADDIN_GROUP_STATE_IDLE;
	case ALADDIN_RUNNING1:
	case ALADDIN_RUNNING2:
	case ALADDIN_PUSHING:
		return ALADDIN_GROUP_STATE_RUNNING;
	case ALADDIN_JUMPING:
	case ALADDIN_JUMPING_FOWARD:
		return ALADDIN_GROUP_STATE_JUMPPING;
	case ALADDIN_STAYING_ATTACKING:
	case ALADDIN_SITTING_ATTACKING:
	case ALADDIN_STAYING_COMBO_ATTACKING:
	case ALADDIN_RUNING_ATTACKING:
	case ALADDIN_JUMPING_ATTACKING:
	case ALADDIN_STAYING_ATTACKING_BY_APPLE:
	case ALADDIN_SITTING_ATACKING_BY_APPLE:
	case ALADDIN_RUNNING_ATTACKING_BY_APPLE:
	case ALADDIN_JUMPING_ATTACKING_BY_APPLE:
		return ALADDIN_GROUP_STATE_ATTACKING;
	case ALADDIN_CLIMBING:
	case ALADDIN_FALLING:
		return ALADDIN_GROUP_STATE_CLIMBING;
	default:
		return ALADDIN_GROUP_STATE_END;
	}
}

int Aladdin::GetCurrentGroupState()
{
	return GetGroupState(currentState);
}
