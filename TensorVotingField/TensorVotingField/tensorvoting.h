#if !defined ( _TENSORVOTING_H_ )
#define _TENSORVOTING_H_

#include "Common.h"


class TVF;
typedef TVF* tvf_ptr;


/// @brief		�ټ������ʵ� ��ü�� ���� (��� ��� ���ʿ� ����)
/// @param		simga			[in] �����ʵ��� ũ��� ������ �����ϴ� ��.
/// @return		Reentrant�� ���� �ټ������ʵ� ��ü�� ��ȯ
tvf_ptr createTVF(double sigma);

/// @brief		�ټ������ʵ� ��ü�� ���� (��� ��� �������� ����)
/// @param		tvf_ptr		[in] createTVF()�� ������ ��ü.
/// @return		void
void	destroyTVF(tvf_ptr tvf);

/// @brief		������ �ټ������ʵ��� �ʺ� ���̸� ��ȯ
/// @param		tvf			[in] �ʺ� ���̸� ������ �ټ������ʵ� ��ü.
/// @return		�ټ������ʵ��� width�� ��ȯ
int		getTVFWindowSize(tvf_ptr tvf);

/// @brief		������ �ټ������ʵ��� �� ũ��(windowSize^2)�� ��ȯ
/// @param		tvf			[in] �� ũ�⸦ ������ �ټ������ʵ� ��ü.
/// @return		�ټ������ʵ��� full size�� ��ȯ
int		getTVFFullSize(tvf_ptr tvf);

/// @brief		������ �ټ������ʵ� ������(double **)�� ��ȯ
/// @param		tvf			[in] �ټ������ʵ� �����͸� ������ �ټ������ʵ� ��ü.
/// @return		�ټ������ʵ����� �ּҸ� ��ȯ
TensorArray getVotingField(tvf_ptr tvf);

/// @brief		�ش� ��ġ�� �ټ�(double*)�� ��ȯ
/// @param		tvf			[in] �ټ��� ������ �ټ������ʵ� ��ü.
/// @param		w			[in] x�� ��ġ
/// @param		h			[in] y�� ��ġ
/// @return		�ټ��ּҸ� ��ȯ
Tensor	getTensorElements(tvf_ptr tvf, int w, int h);

/// @brief		�ش� ��ġ�� �ټ�(double*)�� �־��� �迭(t[])�� ����
/// @param		tvf			[in] �ټ��� ������ �ټ������ʵ� ��ü.
/// @param		t[]			[out] �ټ��� ������ �迭�ּ�
/// @param		w			[in] x�� ��ġ
/// @param		h			[in] y�� ��ġ
/// @return		N/A
void	getTensorElements(tvf_ptr tvf, double t[], int w, int h);

/// @brief		�־��� �ټ����� ������, ���� ���͸� ����
/// @param		t			[in] �������� ������ �ټ�.
/// @param		e1			[out] 1��° ��������.
/// @param		e2			[out] 2��° ��������
/// @param		l1			[out] 1��° ������.
/// @return		l2			[out] 2��° ������.
/// @return		N/A
void	convertTensorToEigen(Tensor t, Vector e1, Vector e2, double &l1, double &l2);

/// @brief		�־��� ���� ������ �̿��� �ټ������� �����ϰ� �ʱ�ȭ �Ѵ�.
/// @param		bImage			[in] �ټ� ������ ����� ���� ���� ����.
/// @param		imageSize		[in] ������ ũ��. width * height
/// @return		2���� �ټ������� ��ȯ
TensorArray initTensorImage(unsigned char *bImage, int imageSize);



#endif	// !_TENSORVOTING_H_