export module InterfaceWindow;

export class IWindow
{
public:
    IWindow() = default;
    virtual ~IWindow() = default;

    virtual void create() = 0;
    virtual void close() = 0;
    virtual void clear() = 0;
    virtual void begin_draw() = 0;
    virtual void end_draw() = 0;
    virtual void update() = 0;
    virtual void handle_events() = 0;
    
    virtual bool is_open() const = 0;
    virtual bool is_done() = 0;
    virtual bool is_fullscreen() = 0;
    virtual bool is_focused() = 0;
};