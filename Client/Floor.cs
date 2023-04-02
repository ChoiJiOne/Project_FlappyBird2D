/**
 * @brief 게임의 바닥 오브젝트입니다.
 */
class Floor : IGameObject
{
    /**
     * @brief 게임의 바닥 오브젝트 속성에 대한 Getter/Setter 입니다.
     */
    public float Speed
    {
        get => speed_;
        set => speed_ = value;
    }

    public bool Movable
    {
        get => bIsMove_;
        set => bIsMove_ = value;
    }

    public RigidBody RigidBody
    {
        get => rigidBody_;
        set => rigidBody_ = value;
    }


    /**
     * @brief 게임의 바닥 오브젝트를 업데이트합니다.
     * 
     * @param deltaSeconds 초단위 델타 시간값입니다.
     */
    public void Update(float deltaSeconds)
    {
        if (bIsMove_)
        {
            accumulateTime_ += deltaSeconds;
        }

        if(accumulateTime_ > speed_)
        {
            accumulateTime_ -= speed_;
        }
    }


    /**
     * @brief 게임의 바닥 오브젝트를 화면에 그립니다.
     */
    public void Render()
    {
        float factor = accumulateTime_ / speed_;

        Texture floorTexture = ContentManager.Get().GetTexture("Floor");

        RenderManager.Get().DrawHorizonScrollingTexture(
            ref floorTexture, 
            rigidBody_.Center, 
            rigidBody_.Width, 
            rigidBody_.Height, 
            factor
        );
    }


    /**
     * @brief 게임의 바닥이 현재 이동 중인지 확인합니다.
     */
    private bool bIsMove_ = false;


    /**
     * @brief 게임 바닥 오브젝트의 누적 시간입니다.
     * 
     * @note 단위는 초단위입니다.
     */
    private float accumulateTime_ = 0.0f;


    /**
     * @brief 게임의 바닥 이동 속도입니다.
     */
    private float speed_ = 0.0f;


    /**
     * @brief 게임 바닥 오브젝트의 강체입니다.
     */
    private RigidBody rigidBody_;
}