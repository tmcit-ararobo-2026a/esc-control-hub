# ESC Control Hub

gn10-canからの命令で絶縁したCANバスを用いてC620/C610と通信しBLDCを制御する基板とそのファームウェア
VESCによる投擲機構制御に対応したファームウェアは[vesc-hub](https://github.com/tmcit-ararobo-2026a/vesc-hub)にあります。

## 目次

1. [概要](#1-概要)
2. [ドキュメント](#2-ドキュメント)
3. [コントリビューション](#3-コントリビューション)
4. [ビルド・使い方](#4-ビルド使い方)
5. [システム構成](#5-システム構成)
6. [ライセンス](#6-ライセンス)

## 1. 概要

C610/C620などのESCのCANバスは駆動系統と絶縁されておらず、プロトコルもgn10-canではないため、ロボット中枢のCANバスに接続できない。
このESC Control Hubを用いることでCANバスを電気的に絶縁し、プロトコル変換・PID制御・リミットスイッチ制御が可能となる。

## 2. ドキュメント

| ドキュメント | 説明 |
| :-: | :-: |
| [CONTRIBUTING.md](./CONTRIBUTING.md) | 開発フロー・コミット規約・コーディング規約 |
| [docs/requirements-definition.md](./docs/requirements-definition.md) | 要件定義書 |
| [docs/coding-rules.md](./docs/coding-rules.md) | コーディング規約の詳細 |
| [docs/uml/](./docs/uml/) | UML図 |

## 3. コントリビューション

[CONTRIBUTING.md](./CONTRIBUTING.md) を参照してください。

## 4. ビルド・使い方

<!-- ビルドのやり方 -->
<!-- 使い方 -->

## 5. システム構成

<!-- ROS2ノード構成・STM32との通信方式・ハードウェア構成 等 -->
<!-- 依存クラスが3つ以上ある場合は docs/uml/ にUML図を作成し、ここにリンクする -->

## 6. ライセンス

本リポジトリは [MITライセンス](./LICENSE) のもとで公開されています。
