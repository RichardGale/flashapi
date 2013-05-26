#if !defined(FLEX11_6_FLASH_DISPLAY_STAGEALIGN_AS)
#define FLEX11_6_FLASH_DISPLAY_STAGEALIGN_AS
#if defined(__cplusplus)


/**
 * The StageAlign class provides constant values to use for the <codeph class="+ topic/ph pr-d/codeph ">Stage.align</codeph> property.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



namespace flash
{
    namespace display
    {
        class StageAlign : public Object
        {
            /**
             * Specifies that the Stage is aligned at the top.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOP;

            /**
             * Specifies that the Stage is aligned on the left.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string LEFT;

            /**
             * Specifies that the Stage is aligned at the bottom.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string BOTTOM;

            /**
             * Specifies that the Stage is aligned to the right.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string RIGHT;

            /**
             * Specifies that the Stage is aligned in the top-left corner.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOP_LEFT;

            /**
             * Specifies that the Stage is aligned in the top-right corner.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string TOP_RIGHT;

            /**
             * Specifies that the Stage is aligned in the bottom-left corner.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string BOTTOM_LEFT;

            /**
             * Specifies that the Stage is aligned in the bottom-right corner.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string BOTTOM_RIGHT;

        public:
            StageAlign();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY_STAGEALIGN_AS
#endif // __cplusplus

