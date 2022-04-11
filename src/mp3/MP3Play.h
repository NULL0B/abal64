//
// MPEG1 Audio Layer-3 Class Header
// Copyright(C) 2000 by TOx2RO / O2 Software All rights reserved.
//
// MP3Play.h
//

#ifndef __MP3PLAY_H__
#define __MP3PLAY_H__

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <process.h>
#include ".\\include\\mp3dec.h"

const WORD MaxBufferingNumber = 64;				// �ő�o�b�t�@�����O�t���[����(�K���W�ȏ���w��)

// �Đ���
enum PlayState
{
	Closed,
	Opened,
	Playing,
	Paused
};

// �G���[�R�[�h
enum Error
{
	NoError,									// �G���[�Ȃ�
	NoFile,										// �t�@�C����������Ȃ�
	NoMP3,										// �l�o�R�ł͂Ȃ�
	NoMemory,									// �������[�s��
	UnknownError								// ���m�̃G���[
};

// 10-Bands Equalizer
struct EQ
{
	signed char _60;							// 60Hz
	signed char _170;							// 170Hz
	signed char _310;							// 310Hz
	signed char _600;							// 600Hz
	signed char _1k;							// 1kHz
	signed char _3k;							// 3kHz
	signed char _6k;							// 6kHz
	signed char _12k;							// 12kHz
	signed char _14k;							// 14kHz
	signed char _16k;							// 16kHz
};

class MP3Play {
public:
	MP3Play();									// �R���X�g���N�^
	~MP3Play();									// �f�X�g���N�^
	LRESULT	Open(LPSTR mp3file);				// �l�o�R�t�@�C�����J��
	LRESULT Close();							// �l�o�R�t�@�C�������
	LRESULT Play(DWORD start,DWORD end);		// �Đ�
	LRESULT LoopPlay(DWORD start,				// ���[�v�Đ�
					 DWORD end,
					 DWORD loop,
					 DWORD number);
	LRESULT Pause();							// �ꎞ��~
	LRESULT Resume();							// �ꎞ��~����
	LRESULT Stop();								// ��~
	LRESULT Equalize(EQ eq);					// �C�R���C�U�[

private:
	// waveOut �R�[���o�b�N�֐�
	static void CALLBACK waveOutProc(HWAVE hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2);
	// �f�R�[�h�X���b�h
	static DWORD WINAPI DecodeFunc(LPVOID dwInstance); 
	// �~���b���t���[���ɕϊ�
	inline DWORD msec2frame(DWORD msec);
	// �t���[�����~���b�ɕϊ�
	inline DWORD frame2msec(DWORD frame);
	// �~���b���o�C�g�ɕϊ�(PCM)
	inline DWORD msec2bytes(DWORD bytes);

private:
	PlayState State;							// �Đ���
	DWORD LoopCount;							// ���[�v�J�E���^
	DWORD Partition;							// ���ݍĐ����Ă���u���b�N
	BYTE sw;									// �_�u���o�b�t�@�����O�p�X�C�b�`
	DWORD BufferingNumber;						// �o�b�t�@�����O�t���[����

	HANDLE ThreadHandle;						// �l�o�R�f�R�[�h�X���b�h�n���h��
	DWORD ThreadID;								// �l�o�R�f�R�[�h�X���b�h�h�c

	HANDLE FileHandle;							// �l�o�R�t�@�C���n���h��
	HANDLE MapFile;								// �l�o�R�t�@�C���}�b�s���O�I�u�W�F�N�g
	BYTE* pSrcFile;								// �l�o�R�t�@�C���̊J�n�A�h���X
	BYTE* pFrameData;							// �f�[�^�J�n�A�h���X(�t�@�C���J�n�A�h���X�{�w�b�_)
	DWORD NowPos;
	HWAVEOUT WaveOut;							// �o�̓f�o�C�X�̃n���h��
	WAVEFORMATEX PCMwf;							// �o�b�l��WAVEFORMAT�\����

	MPEG_DECODE_PARAM MP3DP[2];					// �l�o�R�f�R�[�h���
	MPEG_DECODE_INFO MP3DI;

	WAVEHDR PCMwh[2];							// �o�b�l�f�[�^�o�b�t�@�w�b�_�[
	LPVOID Buffer[2];							// �o�b�l�f�[�^�o�b�t�@�ւ̃|�C���^

	LPSTR FileName;								// �l�o�R�t�@�C���l�[��
	DWORD FileSize;								// �l�o�R�t�@�C���T�C�Y
	DWORD PartitionNumber;						// �Đ������̕�����(�Đ��T�C�Y���o�b�t�@�T�C�Y)
	DWORD startSec;								// �Đ��J�n�ʒu(�~���b)
	DWORD endSec;								// �Đ��I���ʒu(�~���b)
	DWORD loopSec;								// ���[�v�J�n�ʒu(�~���b)
	BYTE LoopMode;								// �Đ����[�h(0:�ʏ�Đ� 1:���[�v�Đ�)
	bool NowLooping;							// ���݃��[�v����(true:���[�v�� false:���[�v���ł͂Ȃ�)
	bool InfiniteLoop;							// �������[�v��(true:�������[�v false:�������[�v�ł͂Ȃ�)

	WORD MpegSpec;								// �l�o�d�f�̃o�[�W����
	WORD Bitrate;								// �r�b�g���[�g
	WORD Frequency;								// �T���v�����O���[�g
	WORD Channel;								// �`�����l����
	WORD FrameSize;								// �t���[���T�C�Y
};
#endif