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

const WORD MaxBufferingNumber = 64;				// 最大バッファリングフレーム数(必ず８以上を指定)

// 再生状況
enum PlayState
{
	Closed,
	Opened,
	Playing,
	Paused
};

// エラーコード
enum Error
{
	NoError,									// エラーなし
	NoFile,										// ファイルが見つからない
	NoMP3,										// ＭＰ３ではない
	NoMemory,									// メモリー不足
	UnknownError								// 未知のエラー
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
	MP3Play();									// コンストラクタ
	~MP3Play();									// デストラクタ
	LRESULT	Open(LPSTR mp3file);				// ＭＰ３ファイルを開く
	LRESULT Close();							// ＭＰ３ファイルを閉じる
	LRESULT Play(DWORD start,DWORD end);		// 再生
	LRESULT LoopPlay(DWORD start,				// ループ再生
					 DWORD end,
					 DWORD loop,
					 DWORD number);
	LRESULT Pause();							// 一時停止
	LRESULT Resume();							// 一時停止解除
	LRESULT Stop();								// 停止
	LRESULT Equalize(EQ eq);					// イコライザー

private:
	// waveOut コールバック関数
	static void CALLBACK waveOutProc(HWAVE hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2);
	// デコードスレッド
	static DWORD WINAPI DecodeFunc(LPVOID dwInstance); 
	// ミリ秒をフレームに変換
	inline DWORD msec2frame(DWORD msec);
	// フレームをミリ秒に変換
	inline DWORD frame2msec(DWORD frame);
	// ミリ秒をバイトに変換(PCM)
	inline DWORD msec2bytes(DWORD bytes);

private:
	PlayState State;							// 再生状況
	DWORD LoopCount;							// ループカウンタ
	DWORD Partition;							// 現在再生しているブロック
	BYTE sw;									// ダブルバッファリング用スイッチ
	DWORD BufferingNumber;						// バッファリングフレーム数

	HANDLE ThreadHandle;						// ＭＰ３デコードスレッドハンドル
	DWORD ThreadID;								// ＭＰ３デコードスレッドＩＤ

	HANDLE FileHandle;							// ＭＰ３ファイルハンドル
	HANDLE MapFile;								// ＭＰ３ファイルマッピングオブジェクト
	BYTE* pSrcFile;								// ＭＰ３ファイルの開始アドレス
	BYTE* pFrameData;							// データ開始アドレス(ファイル開始アドレス＋ヘッダ)
	DWORD NowPos;
	HWAVEOUT WaveOut;							// 出力デバイスのハンドル
	WAVEFORMATEX PCMwf;							// ＰＣＭのWAVEFORMAT構造体

	MPEG_DECODE_PARAM MP3DP[2];					// ＭＰ３デコード情報
	MPEG_DECODE_INFO MP3DI;

	WAVEHDR PCMwh[2];							// ＰＣＭデータバッファヘッダー
	LPVOID Buffer[2];							// ＰＣＭデータバッファへのポインタ

	LPSTR FileName;								// ＭＰ３ファイルネーム
	DWORD FileSize;								// ＭＰ３ファイルサイズ
	DWORD PartitionNumber;						// 再生部分の分割数(再生サイズ÷バッファサイズ)
	DWORD startSec;								// 再生開始位置(ミリ秒)
	DWORD endSec;								// 再生終了位置(ミリ秒)
	DWORD loopSec;								// ループ開始位置(ミリ秒)
	BYTE LoopMode;								// 再生モード(0:通常再生 1:ループ再生)
	bool NowLooping;							// 現在ループ中か(true:ループ中 false:ループ中ではない)
	bool InfiniteLoop;							// 無限ループか(true:無限ループ false:無限ループではない)

	WORD MpegSpec;								// ＭＰＥＧのバージョン
	WORD Bitrate;								// ビットレート
	WORD Frequency;								// サンプリングレート
	WORD Channel;								// チャンネル数
	WORD FrameSize;								// フレームサイズ
};
#endif