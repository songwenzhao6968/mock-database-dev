SELECT AVG_CLOSING_PRICE(*) FROM t_transaction WHERE (user_id = 12) AND (asset_type = "Cash") AND (date >= 20221001) AND (date <= 20221003)
SELECT COUNT(*) FROM t_transaction WHERE (user_id = 5) AND (is_buy = true)
