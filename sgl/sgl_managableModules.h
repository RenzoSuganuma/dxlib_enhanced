#pragma once

// sglライブラリで管理できるモジュールすべてが継承すべきインタフェース
class IManagableModule {

	/* --- システム側からコールする関数 --- */
public:
	// モジュールの初期化
	virtual void __initialize() = 0;				// order - 0
	// モジュールの更新
	virtual void __update(float delta_time) = 0;	// order - 1
	// モジュールの描画
	virtual void __draw() = 0;						// order - 2
	// モジュールの破棄
	virtual void __finalize() = 0;					// order - 3
	// モジュール内での解放
	virtual void __release() = 0;					// order - 4

	/*
	// モジュールの初期化
	void __initialize();
	// モジュールの更新
	void __update(float delta_time);
	// モジュールの描画
	void __draw();
	// モジュール内での解放
	void __release();
	// モジュールの破棄
	void __finalize();
	*/

	/* --- ユーザー定義モジュールでoverrideする関数 --- */

protected:
	// モジュールの初期化
	virtual void Initialize() = 0;
	// モジュールの更新
	virtual void Update(float delta_time) = 0;
	// モジュールの描画
	virtual void Draw() = 0;
	// モジュールの内での解放
	virtual void Release() = 0;
	// モジュールの破棄
	virtual void Finalize() = 0;

	/*
	// モジュールの初期化
	virtual void Initialize();
	// モジュールの更新
	virtual void Update(float delta_time);
	// モジュールの描画
	virtual void Draw();
	// モジュールの内での解放
	virtual void Release();
	// モジュールの破棄
	virtual void Finalize();
	*/
};