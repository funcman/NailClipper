#ifndef NCCOMMON_H
#define NCCOMMON_H

#define NC_BLEND_COLORADD       1
#define NC_BLEND_COLORMUL       0

#define NC_BLEND_ALPHABLEND     2
#define NC_BLEND_ALPHAADD       0

#define NC_BLEND_ZWRITE         4
#define NC_BLEND_NOZWRITE       0

#define NC_BLEND_DEFAULT        (NC_BLEND_COLORMUL | NC_BLEND_ALPHABLEND | NC_BLEND_NOZWRITE)
#define NC_BLEND_DEFAULT_Z      (NC_BLEND_COLORMUL | NC_BLEND_ALPHABLEND | NC_BLEND_ZWRITE)

#endif//NCCOMMON_H
