#if !defined ( _TVF_H_ )
#define	_TVF_H_

#include "Common.h"
#include "Tensor.h"

///////////////////////////////////////
// class TVF
class TVF{
private:
	// array
	TensorArray	_vf;			// ���� �ʵ� ����Ÿ

	// variable
	double		_sigma;			// �����ʵ��� ũ��� ������ ��������.
	int			_wSize;			// sigma�� �̿��� ���� ���� �ʵ��� �ʺ� ����.
	int			_wsHalf;		// �ʺ��� ���� ����
	int			_vfSize;		// sigma�� �̿��� ���� ���� �ʵ��� �� ũ��. (wSize * wSize)
	int			_nSvf;		// ball voting field ������ ����� stick voting field�� ����
protected:
	// functions
	int calcWindowSize(double sigma);
	void initVotingField();			// ��ƽ ���� �ʵ带 ȸ��/�������� ������ �ʵ带 ���.

public:
	// constructors
	TVF(double sigma=18.0, int nSvf=32);
	~TVF();

	///////////////////////////
	// functions
	int getWindowSize();			// ���ο� ���� �ʵ带 ����� ���� ũ�⸦ ��� �Լ�
	int getHalfWindowSize();
	int getFullSize();				// �����ʵ� �迭�� �� ũ�� (�ʺ�*�ʺ�*������^2)
	double getSigma();
	TensorArray getVF();
	///////////////////////////
	// operator
	Tensor operator [](int idx) const 
	{
		return _vf[idx];
	}	
};

#endif	// !_TVF_H_