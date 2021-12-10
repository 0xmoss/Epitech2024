using System.Collections.Generic;

using Newtonsoft.Json;

namespace Dashboard.Pages
{
    public class CoffeeSubscriptions
    {
        public class Datum
        {
            public int subscription_id { get; set; }
            public object subscription_cancelled_on { get; set; }
            public string subscription_created_on { get; set; }
            public string subscription_updated_on { get; set; }
            public string subscription_current_period_start { get; set; }
            public string subscription_current_period_end { get; set; }
            public string subscription_coffee_price { get; set; }
            public int subscription_coffee_num { get; set; }
            public object subscription_is_cancelled { get; set; }
            public object subscription_is_cancelled_at_period_end { get; set; }
            public string subscription_currency { get; set; }
            public object subscription_message { get; set; }
            public int message_visibility { get; set; }
            public string subscription_duration_type { get; set; }
            public object referer { get; set; }
            public object country { get; set; }
            public string transaction_id { get; set; }
            public string payer_email { get; set; }
            public string payer_name { get; set; }
        }

        public class Root
        {
            public int current_page { get; set; }
            public List<Datum> data { get; set; }
            public string first_page_url { get; set; }
            public int from { get; set; }
            public int last_page { get; set; }
            public string last_page_url { get; set; }
            public string next_page_url { get; set; }
            public string path { get; set; }
            public int per_page { get; set; }
            public object prev_page_url { get; set; }
            public int to { get; set; }
            public int total { get; set; }
        }
    }

    public class CoffeeSupporters
    {
        public class Datum
        {
            public int support_id { get; set; }
            public object support_note { get; set; }
            public int support_coffees { get; set; }
            public string transaction_id { get; set; }
            public int support_visibility { get; set; }
            public string support_created_on { get; set; }
            public string support_updated_on { get; set; }
            public object transfer_id { get; set; }
            public object supporter_name { get; set; }
            public string support_coffee_price { get; set; }
            public string support_email { get; set; }
            public object is_refunded { get; set; }
            public string support_currency { get; set; }
            public int support_note_pinned { get; set; }
            public object referer { get; set; }
            public string country { get; set; }
            public string payer_email { get; set; }
            public string payment_platform { get; set; }
            public string payer_name { get; set; }
        }

        public class Root
        {
            public int current_page { get; set; }
            public List<Datum> data { get; set; }
            public string first_page_url { get; set; }
            public int from { get; set; }
            public int last_page { get; set; }
            public string last_page_url { get; set; }
            public string next_page_url { get; set; }
            public string path { get; set; }
            public int per_page { get; set; }
            public object prev_page_url { get; set; }
            public int to { get; set; }
            public int total { get; set; }
        }


    }

    public class CoffeeExtras
    {
        public class Extra
        {
            public int reward_id { get; set; }
            public string reward_title { get; set; }
            public string reward_description { get; set; }
            public string reward_confirmation_message { get; set; }
            public string reward_question { get; set; }
            public int reward_used { get; set; }
            public string reward_created_on { get; set; }
            public string reward_updated_on { get; set; }
            public object reward_deleted_on { get; set; }
            public int reward_is_active { get; set; }
            public string reward_image { get; set; }
            public int? reward_slots { get; set; }
            public string reward_coffee_price { get; set; }
            public int reward_order { get; set; }
        }

        public class Datum
        {
            public int purchase_id { get; set; }
            public string purchased_on { get; set; }
            public string purchase_updated_on { get; set; }
            public int purchase_is_revoked { get; set; }
            public string purchase_amount { get; set; }
            public string purchase_currency { get; set; }
            public string purchase_question { get; set; }
            public string payer_email { get; set; }
            public string payer_name { get; set; }
            public Extra extra { get; set; }
        }

        public class Root
        {
            public int current_page { get; set; }
            public List<Datum> data { get; set; }
            public string first_page_url { get; set; }
            public int from { get; set; }
            public int last_page { get; set; }
            public string last_page_url { get; set; }
            public object next_page_url { get; set; }
            public string path { get; set; }
            public int per_page { get; set; }
            public object prev_page_url { get; set; }
            public int to { get; set; }
            public int total { get; set; }
        }


    }
}
