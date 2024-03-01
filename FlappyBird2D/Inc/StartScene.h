#pragma once

#include <functional>
#include <vector>

#include "IEntity.h"
#include "IScene.h"


/**
 * @brief ���� ���Դϴ�.
 */
class StartScene : public IScene
{
public:
	/**
	 * @brief ���� ���� ����Ʈ �������Դϴ�.
	 */
	StartScene() = default;


	/**
	 * @brief ���� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~StartScene() {}


	/**
	 * @brief ���� ���� ���� ������ �� ���� �����ڸ� ���������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(StartScene);


	/**
	 * @brief ���� ���� �� �������� �����մϴ�.
	 *
	 * @param deltaSeconds �� ���� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief ���� ���� �����մϴ�.
	 */
	virtual void Enter() override;


	/**
	 * @brief ���� ������ �����ϴ�.
	 */
	virtual void Exit() override;


	/**
	 * @brief ���� ���� �̺�Ʈ�� �����մϴ�.
	 * 
	 * @param quitLoopEvent ������ ���� ���� �̺�Ʈ�Դϴ�.
	 */
	void SetQuitLoopEvent(const std::function<void()>& quitLoopEvent) { quitLoopEvent_ = quitLoopEvent;	}


	/**
	 * @brief �÷��� ���� �����մϴ�.
	 * 
	 * @param playScene ������ �÷��� ���� �������Դϴ�.
	 */
	void SetPlayScene(IScene* playScene) { playScene_ = playScene; }


	/**
	 * @brief ���� ���� �����մϴ�.
	 * 
	 * @param settingScene ������ ���� ���� �������Դϴ�.
	 */
	void SetSettingScene(IScene* settingScene) { settingScene_ = settingScene; }


private:
	/**
	 * @brief ���� ���� �̺�Ʈ�Դϴ�.
	 */
	std::function<void()> quitLoopEvent_;


	/**
	 * @brief �÷��� �� �Դϴ�.
	 */
	IScene* playScene_ = nullptr;


	/**
	 * @brief ���� ���Դϴ�.
	 */
	IScene* settingScene_ = nullptr;


	/**
	 * @brief ��ƼƼ ����Դϴ�.
	 */
	std::vector<EUID> entities_;
};