#if !defined(FLEX11_6_UNINITIALIZEDERROR_AS)
#define FLEX11_6_UNINITIALIZEDERROR_AS
#if defined(__cplusplus)



class UninitializedError: public Error
{
public:
    static const int length;

public:
    UninitializedError(void *message, void *id);
};

#endif // FLEX11_6_UNINITIALIZEDERROR_AS
#endif // __cplusplus

