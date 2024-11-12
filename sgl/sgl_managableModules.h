#pragma once

// sgl���C�u�����ŊǗ��ł��郂�W���[�����ׂĂ��p�����ׂ��C���^�t�F�[�X
class IManagableModule {

	/* --- �V�X�e��������R�[������֐� --- */
public:
	// ���W���[���̏�����
	virtual void __initialize() = 0;				// order - 0
	// ���W���[���̍X�V
	virtual void __update(float delta_time) = 0;	// order - 1
	// ���W���[���̕`��
	virtual void __draw() = 0;						// order - 2
	// ���W���[���̔j��
	virtual void __finalize() = 0;					// order - 3
	// ���W���[�����ł̉��
	virtual void __release() = 0;					// order - 4

	/*
	// ���W���[���̏�����
	void __initialize();
	// ���W���[���̍X�V
	void __update(float delta_time);
	// ���W���[���̕`��
	void __draw();
	// ���W���[�����ł̉��
	void __release();
	// ���W���[���̔j��
	void __finalize();
	*/

	/* --- ���[�U�[��`���W���[����override����֐� --- */

protected:
	// ���W���[���̏�����
	virtual void Initialize() = 0;
	// ���W���[���̍X�V
	virtual void Update(float delta_time) = 0;
	// ���W���[���̕`��
	virtual void Draw() = 0;
	// ���W���[���̓��ł̉��
	virtual void Release() = 0;
	// ���W���[���̔j��
	virtual void Finalize() = 0;

	/*
	// ���W���[���̏�����
	virtual void Initialize();
	// ���W���[���̍X�V
	virtual void Update(float delta_time);
	// ���W���[���̕`��
	virtual void Draw();
	// ���W���[���̓��ł̉��
	virtual void Release();
	// ���W���[���̔j��
	virtual void Finalize();
	*/
};