#pragma once

#include <cstdint>

#include "Macro.h"


/**
 * @brief 엔티티 인터페이스입니다.
 */
class IEntity
{
public:
	/**
	 * @brief 엔티티 인터페이스의 디폴트 생성자입니다.
	 */
	IEntity() = default;


	/**
	 * @brief 엔티티 인터페이스의 가상 소멸자입니다.
	 */
	virtual ~IEntity() {}


	/**
	 * @brief 엔티티 인터페이스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IEntity);


	/**
	 * @brief 엔티티를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 * 
	 * @note 
	 * - 엔티티 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 * - 델타 시간 값은 초단위입니다.
	 */
	virtual void Tick(float deltaSeconds) = 0;


	/**
	 * @brief 엔티티를 화면에 그립니다.
	 */
	virtual void Render() = 0;


	/**
	 * @brief 엔티티 내의 리소스를 할당 해제합니다.
	 *
	 * @note 엔티티 인터페이스를 상속받는 하위 클래스에서 반드시 구현해야 합니다.
	 */
	virtual void Release() = 0;


	/**
	 * @brief 엔티티가 초기화된 적이 있는지 확인합니다.
	 *
	 * @return 엔티티가 초기화된 적이 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsInitialized() const { return bIsInitialized_; }


protected:
	/**
	 * @brief 엔티티가 초기화되었는지 확인합니다.
	 */
	bool bIsInitialized_ = false;
};


/**
 * @brief 엔티티의 고유 아이디(Entity Unique Identity)입니다.
 */
using EUID = uint32_t;