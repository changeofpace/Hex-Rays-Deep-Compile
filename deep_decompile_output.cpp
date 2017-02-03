// prototypes of called functions:
//    void __fastcall sub_180676AC0(__int64 a1, __int64 a2);
//    int __usercall sub_18058A4D0@<eax>(__int64 a1@<rdx>, __int64 a2@<rcx>, unsigned int a3@<r8d>, signed int a4@<r9d>, float a5@<xmm0>);
//    int __fastcall sub_1800E8DB0(__int64 a1, float a2, __int64 a3, __int64 a4, int a5);

void __fastcall sub_1800E8930(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
    __int64 v4; // rbp@1
    __int64 v5; // rsi@1
    __int64 v6; // rdi@1
    __int64 v7; // rbx@1
    unsigned int v8; // eax@2
    signed int v9; // er9@3
    __int64 v10; // [sp+30h] [bp-28h]@1
    float v11; // [sp+38h] [bp-20h]@1
    __int64 v12; // [sp+40h] [bp-18h]@3
    float v13; // [sp+48h] [bp-10h]@3

    v4 = a4;
    v5 = a3;
    v6 = a2;
    v7 = a1;
    *&v10 = *(a4 + 0xC) - (*a3 * 4.0);
    *(&v10 + 1) = *(a4 + 0x10) - (*(a3 + 4) * 4.0);
    v11 = *(a4 + 0x14) - (*(a3 + 8) * 4.0);
    if ( *(a1 + 0x1C9) )
    {
        sub_180676AC0(a2, a1);
        v8 = (*(*v7 + 0x488i64))(v7);
        if ( v8 != 0xFFFFFFFF )
        {
            v9 = ffloor(*(v6 + 0x44));
            v13 = v11;
            v12 = v10;
            sub_18058A4D0(v5, &v12, v8, v9, *&v10);
            sub_1800E8DB0(v7, *(v6 + 0x44), v5, v4, *(v6 + 0x50));
        }
    }
}