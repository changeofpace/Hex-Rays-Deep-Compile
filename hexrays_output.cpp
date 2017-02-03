// prototypes of called functions:
//    void __fastcall sub_180676AC0(__int64 a1, __int64 a2);
//    int __usercall sub_18058A4D0@<eax>(__int64 a1@<rdx>, __int64 a2@<rcx>, unsigned int a3@<r8d>, signed int a4@<r9d>, float a5@<xmm0>);
//    int __fastcall sub_1800E8DB0(__int64 a1, float a2, __int64 a3, __int64 a4, int a5);

void __fastcall sub_1800E8930(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
    __int64 v4; // rsi@1
    __int64 v5; // rdi@1
    __int64 v6; // rbx@1
    int v7; // eax@2
    __int64 v8; // r9@3
    __int128 v9; // xmm1@3
    int v10; // ST20_4@3
    __int64 v11; // [sp+30h] [bp-28h]@1
    float v12; // [sp+38h] [bp-20h]@1
    __int64 v13; // [sp+40h] [bp-18h]@3
    float v14; // [sp+48h] [bp-10h]@3

    v4 = a3;
    v5 = a2;
    v6 = a1;
    *&v11 = *(a4 + 0xC) - (*a3 * 4.0);
    *(&v11 + 1) = *(a4 + 0x10) - (*(a3 + 4) * 4.0);
    v12 = *(a4 + 0x14) - (*(a3 + 8) * 4.0);
    if ( *(a1 + 0x1C9) )
    {
        sub_180676AC0(a2, a1);
        v7 = (*(*v6 + 0x488i64))(v6);
        if ( v7 != 0xFFFFFFFF )
        {
            v8 = ffloor(*(v5 + 0x44));
            v14 = v12;
            v13 = v11;
            sub_18058A4D0(&v13, v4, v7, v8);
            v9 = *(v5 + 0x44);
            v10 = *(v5 + 0x50);
            sub_1800E8DB0(v6);
        }
    }
}