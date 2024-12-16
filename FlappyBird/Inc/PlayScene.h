#pragma once

#include <map>
#include <vector>
#include <functional>

#include "IEntity.h"
#include "InputManager.h"
#include "IScene.h"


/**
 * @brief �÷��� ���Դϴ�.
 */
class PlayScene : public IScene
{
public:
	/**
	 * @brief �÷��� ���� ����Ʈ �������Դϴ�.
	 */
	PlayScene() = default;


	/**
	 * @brief �÷��� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~PlayScene() {}


	/**
	 * @brief �÷��� ���� ���� ������ �� ���� �����ڸ� ���������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PlayScene);


	/**
	 * @brief �÷��� ���� �� �������� �����մϴ�.
	 *
	 * @param deltaSeconds �� ���� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float deltaSeconds) override;


	/**
	 * @brief �÷��� ���� �����մϴ�.
	 */
	virtual void Enter() override;


	/**
	 * @brief �÷��� ������ �����ϴ�.
	 */
	virtual void Exit() override;


	/**
	 * @brief ���� ���̵��� ���� �ӵ��� �����մϴ�.
	 * 
	 * @param gameSpeed ������ ���� �ӵ��Դϴ�.
	 */
	void SetGameSpeed(float gameSpeed) { gameSpeed_ = gameSpeed; }


	/**
	 * @brief ��׶��� ��ƼƼ�� ID ���� �����մϴ�.
	 * 
	 * @param id ������ ��׶��� ��ƼƼ�� ID ���Դϴ�.
	 */
	void SetBackgroundID(const EUID& id) { backgroundID_ = id; }


	/**
	 * @brief �ٴ� ��ƼƼ�� ID ���� �����մϴ�.
	 *
	 * @param id ������ �ٴ� ��ƼƼ�� ID ���Դϴ�.
	 */
	void SetLandID(const EUID& id) { landID_ = id; }


	/**
	 * @brief �� ��ƼƼ�� ID ���� �����մϴ�.
	 * 
	 * @param id ������ �� ��ƼƼ�� ID ���Դϴ�.
	 */
	void SetBirdID(const EUID& id) { birdID_ = id; }


	/**
	 * @brief ��ŷ ���� �����մϴ�.
	 * 
	 * @param rankScene ������ ��ŷ ���� �������Դϴ�.
	 */
	void SetRankScene(IScene* rankScene) { rankScene_ = rankScene; }


private:
	/**
	 * @brief ��ŷ ���Դϴ�.
	 */
	IScene* rankScene_ = nullptr;


	/**
	 * @brief ������ �����Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsPause_ = false;


	/**
	 * @brief ī��Ʈ �ٿ��Դϴ�.
	 */
	float countDown_ = 3.0f;


	/**
	 * @brief ���� ���̵��� ���� �ӵ��Դϴ�.
	 */
	float gameSpeed_ = 0.0f;


	/**
	 * @brief ��׶��� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID backgroundID_ = -1;


	/**
	 * @brief �ٴ� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID landID_ = -1;


	/**
	 * @brief ������ ��Ʈ�ѷ� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID pipeController_ = -1;


	/**
	 * @brief �� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID birdID_ = -1;


	/**
	 * @brief ���ھ� ��� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID scoreViewerID_ = -1;


	/**
	 * @brief ���� ���¸� ǥ���� ��ƼƼ�� ID ���Դϴ�.
	 */
	EUID pauseViewerID_ = -1;


	/**
	 * @brief ��ƼƼ ����Դϴ�.
	 */
	std::vector<EUID> entityIDs_;


	/**
	 * @brief �÷��� �� ���� �̺�Ʈ�Դϴ�.
	 */
	std::map<EWindowEvent, WINDOW_EVENT_UID> sceneEvents_;
};