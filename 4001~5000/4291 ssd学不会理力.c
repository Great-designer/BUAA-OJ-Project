#include<stdio.h>

void CrossProduct(long long Result[], long long V1[], long long V2[])
{
	Result[0] = V1[1] * V2[2] - V1[2] * V2[1];
	Result[1] = V1[2] * V2[0] - V1[0] * V2[2];
	Result[2] = V1[0] * V2[1] - V1[1] * V2[0];
// 本函数可以通过向参数中传递储存结果的数组，来实现在main函数中获得计算结果的功能
// 在实践中也常用这一方法来使函数返回一个数组
// 本题限定了坐标维数仅有三维,如果输入的数组长度不能在编写时确定的话，还应该输入一个整数代表数组的长度
}

int main()
{
	int DataNum = 0;
	long long Force[3] = {}; //输入的力
	long long Base[3] = {}; //简化点
	long long Position[3] = {}; //力的作用点
	long long FinalForce[3] = {}; //最终合成的力矢
	long long FinalTorque[3] = {}; //最终合成的力矩
	scanf("%d", &DataNum);
	scanf("%lld %lld %lld", &Base[0], &Base[1], &Base[2]);
	for (int i = 0; i < DataNum; i++)
	{
		scanf("%lld %lld %lld", &Force[0], &Force[1], &Force[2]);
		scanf("%lld %lld %lld", &Position[0], &Position[1], &Position[2]);
		for (int i = 0; i < 3; i++)
		{
			Position[i] -= Base[i];
		}
		long long Torque[3] = {};//用于储存计算结果的数组
		CrossProduct(Torque, Position, Force); //输入储存结果的数组,相对位置矢量,力矢量,得到力矩结果
		for (int i = 0; i < 3; i++)
		{
			FinalForce[i] += Force[i];
			FinalTorque[i] += Torque[i];
		}
	}
	printf("%lld %lld %lld\n", FinalForce[0], FinalForce[1], FinalForce[2]);
	printf("%lld %lld %lld", FinalTorque[0], FinalTorque[1], FinalTorque[2]);
	return 0;
}