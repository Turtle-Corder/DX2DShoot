#pragma once

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vSize;
	D3DXVECTOR3 vDir;
	D3DXVECTOR3 vLook;
	D3DXMATRIX	matWorld;
}INFO;

#endif // !__STRUCT_H__
