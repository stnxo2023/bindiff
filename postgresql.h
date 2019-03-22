// Copyright 2011-2018 Google LLC. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_ZYNAMICS_BINEXPORT_POSTGRESQL_H_
#define THIRD_PARTY_ZYNAMICS_BINEXPORT_POSTGRESQL_H_

#include <string>
#include <vector>

#include "third_party/zynamics/binexport/database.h"
#include "third_party/zynamics/binexport/types.h"
#include "third_party/zynamics/binexport/util/statusor.h"

struct pg_conn;
struct pg_result;

namespace security {
namespace binexport {

class PostgreSqlStatement;

class PostgreSqlDatabase : public Database {
 public:
  static not_absl::StatusOr<std::unique_ptr<PostgreSqlDatabase>> Connect(
      absl::string_view connection_string);

  ~PostgreSqlDatabase() override;

  std::unique_ptr<Statement> Prepare(absl::string_view sql) override;

  string EscapeLiteral(const string& text) const;
  string EscapeIdentifier(const string& text) const;
  //explicit PostgreSqlDatabase(const char* connection_string);
  //Database& Execute(const char* query,
  //                  const Parameters& parameters = Parameters{});
  //Database& Prepare(const char* query, const char* name = "");
  //Database& ExecutePrepared(const Parameters& parameters,
  //                          const char* name = "");
  //operator bool() const;
  //Database& operator>>(bool& value);    // NOLINT
  //Database& operator>>(int32& value);   // NOLINT
  //Database& operator>>(int64& value);   // NOLINT
  //Database& operator>>(double& value);  // NOLINT
  //Database& operator>>(string& value);  // NOLINT
  //Database& operator>>(Blob& value);    // NOLINT
 private:
  friend class PostgreSqlStatement;

  void Begin() override;
  void Commit() override;
  void Rollback() override;

  pg_conn* connection_;
  pg_result* result_;
};

}  // namespace binexport
}  // namespace security

#endif  // THIRD_PARTY_ZYNAMICS_BINEXPORT_POSTGRESQL_H_
