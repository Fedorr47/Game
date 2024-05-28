export module InterfaceState;

export constexpr int INVALID_STATE = -1;

export class IState
{
public:
    IState(const IState& other) = delete;
    IState(IState&& other) = delete;
    IState& operator=(const IState& other) = delete;
    IState& operator=(IState&& other) = delete;

    IState() = default;
    virtual ~IState() = default;

    virtual void on_create() = 0;
    virtual void on_destroy() = 0;

    virtual void activate() = 0;
    virtual void deactivate() = 0;
    
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void handle_input() = 0;

    virtual int get_state_type() const = 0;
};
